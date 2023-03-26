
/* Free RTOS with OTA Support

   https://arduino.stackexchange.com/questions/77004/esp32-is-ota-compatible-with-freertos

*/



#if CONFIG_FREERTOS_UNICORE
#define ARDUINO_RUNNING_CORE 0
#else
#define ARDUINO_RUNNING_CORE 1
#endif

#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif


#define ESP32_RTOS  // Uncomment this line if you want to use the code with freertos only on the ESP32
// Has to be done before including "OTA.h"

#include "OTA.h"
#include "credentials.h"

#include <autoDelay.h>

autoDelay autoDelay;

// Define state machine task
void TaskStateMachine(void *pvParameters);
// define two tasks for Blink & AnalogRead
void TaskBlink( void *pvParameters );
void TaskAnalogReadA3( void *pvParameters );

TaskHandle_t xBlinkHandle;   // Handler for task is passed as argument to task. Only needed for task control if required
TaskHandle_t xSensorHandle;

// the setup function runs once when you press reset or power the board
void setup() {

  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  Serial.println("-ESP32-FreeRTOS- Booting");
  setupOTA("ESP32 - FaerFly", ssid, password);



  // Now set up two tasks to run independently.
  xTaskCreatePinnedToCore(
    TaskStateMachine
    ,"StateMachineTask"
    , 1024
    , NULL
    , 3  // Priority 
    , NULL // State machine should always be active
    , ARDUINO_RUNNING_CORE)

  xTaskCreatePinnedToCore(
    TaskBlink
    ,  "TaskBlink"   // A name just for humans
    ,  1024  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,  NULL
    ,  2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,  &xBlinkHandle    // &xHandle // Set to NULL if handler not required
    ,  ARDUINO_RUNNING_CORE);



  xTaskCreatePinnedToCore(
    TaskAnalogReadA3
    ,  "AnalogReadA3"
    ,  1024  // Stack size
    ,  NULL
    ,  1  // Priority
    ,  &xSensorHandle
    ,  ARDUINO_RUNNING_CORE);

  // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
    vTaskSuspend(xSensorHandle);   // Stops the sensor task before it starts
}

void loop() {
  // Empty. Things are done in Tasks.
#ifdef defined(ESP32_RTOS) && defined(ESP32)
// If RTOS is used then this line is not compiled because its handled by tasks. To Test - Remove this line and see if it still works!
#else
  ArduinoOTA.handle();
#endif

  if (autoDelay.secondsDelay(2)) {  // Testing Task Control Methods
    if (eTaskGetState(xBlinkHandle) == 2){     // enum returned:(0 eReady,1 eRunning,2 eBlocked,3 eSuspended,4 eDeleted)
       vTaskSuspend(xBlinkHandle);
    } else {
       vTaskResume(xBlinkHandle);
    }   
  }
  
}




/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void TaskStateMachine(void *pvParamters){
  (void) pvParamters;   // No Idea what this does why does it here?


  
}


void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  /*
    Blink
    Turns on an LED on for one second, then off for one second, repeatedly.

    If you want to know what pin the on-board LED is connected to on your ESP32 model, check
    the Technical Specs of your board.
  */

  // initialize digital LED_BUILTIN on pin 13 as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelay(50);  // one tick delay (15ms) in between reads for stability
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelay(70);  // one tick delay (15ms) in between reads for stability
  }
}

void TaskAnalogReadA3(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  /*
    AnalogReadSerial
    Reads an analog input on pin A3, prints the result to the serial monitor.
    Graphical representation is available using serial plotter (Tools > Serial Plotter menu)
    Attach the center pin of a potentiometer to pin A3, and the outside pins to +5V and ground.

    This example code is in the public domain.
  */

  for (;;)  {
    // read the input on analog pin A3:
    int sensorValueA3 = analogRead(A3);
    // print out the value you read:
    Serial.println(sensorValueA3);
    vTaskDelay(10);  // one tick delay (15ms) in between reads for stability
  }
}
