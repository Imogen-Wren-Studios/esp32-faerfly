#ESP32 FaerFly - Development Board
 Imogen Wren Business Card PCB
![image](https://user-images.githubusercontent.com/97303986/226198408-7d3f868b-c1ed-464a-bc43-1e919b403036.png)
![image](https://user-images.githubusercontent.com/97303986/226198463-f571905e-49ee-4bfd-8160-80bfb4484ffa.png)
![image](https://user-images.githubusercontent.com/97303986/226198476-26284f6e-2e1c-4ccf-bd85-3f57ea7ba751.png)
![image](https://user-images.githubusercontent.com/97303986/226198490-1007c7fe-2d77-49c3-8209-8892241ad7de.png)





## Project Outline

_The project is a business card that can be handed out at gigs and work, and also a fun project to build!_

### Requirements
 1. A PCB business card I can hand out to people at gigs / work to advertise myself
 2. A fun electronics project or thing

### Ideas
 1. A Ripping Beast of a fuzz I built many years ago out of recycled parts from old broadcast cameras, and have never successfully managed to replicate. <br>
    **Disadvantages:**
    - Limited use as soldering project due to SMD parts
    - Wont be seen once it goes into box
    - Difficulties with supply of Ukranian Transistor


 2. An AtTiny85 based mini pocket lightshow. Rechargable and interactive. Probably get it fabbed so it isnt a soldering project, but include a programming port so it can be reprogrammed easily. <br>
     **Advantages:**
    - Fun programming challenge - Can link to repo with working code in case of bricking
    - Card more likely to be used in the open and interacted with over time
    - Would have to be handed out with everything attached
    - Could exclude battery and make a point of indicating to reuse broken disposible vape for battery. Recycling electronic waste! 


 4. Capacitive touch instrument. Extermal power supply, 9v based for ease. Basic Light Show included? 
    - Analog or Digital?  
    **Analog Advantages** <br>
    - More motivation to treat it as a soldering excercise rather than a programming one.
    - More likely to be of interest to the DIY Music crowd <br>
    **Overall Advantages**
    - could end up being used to make cool music <br>
    **Disadvantages:**
    - Circuit needs testing
    - how sensitive is circuit to change <br>
    
 ## Strech Features
 
 - NFC Tap phone to link to linktree?
 - Edge connectors could be used as both touch interface, and connection to other hardware. Generic port? Is this now a new form we are trying to invent for development boards?
 - 3d printed case for different functions, like exposed touch pins, 
 
 
 ## Circuit Snippets
 
 ### WS2821b LED Implementation
 
 ![image](https://user-images.githubusercontent.com/97303986/219457981-92afcb83-094e-4cd9-8534-0c05b1694e8a.png) <br>
https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf
- Vdd = 3.5 - 5.6 
- Vinput = VDD +-0.5



 Battery can be unregulated direct to LEDs & regulated to microcontroller
Slot for 2nd regulator for powering with 2s? or KISS

I think KISS

### Charging IC and LOw Voltage Cutoff


https://www.mouser.co.uk/ProductDetail/Littelfuse/SMAJ350A?

## Research

### AtTiny85 Interface
**DrAzzy - ATtiny Obsessee**
_Jan '20post #2_
_If you use my core (board manager url in sig), there is a serial bootloader (use the (optiboot) board def).
But you will still need an ISP programmer or arduino running Arduino as ISP sketch to bootload it (usbasps and nano clones are both 3 bucks or so on ebay/aliexpress, either is suitable).
You will also need a 0.1uf cap and 10k resistor for the autoreset circuit so the serial adapter can reset it into the bootloader. (Also, dont forget that you also need a 0.1uf ceramic cap between power and ground close to the t85 ti ensure reliable operation; without this the chip may behave erratically depending on circumstances - I mention this because it is very often omitted in designs I see here, particularly with tinies. You always need this for digital ICs unless otherwise specified in the datasheet. With the t85, if on breadboard or protoboard, i usually put this across the top of the chip to minimize the distance between cap and chip)_

#### USB - SPI Bridge

https://www.mouser.co.uk/ProductDetail/Microchip-Technology/MIC2550AYTS

#### USB C Connectors
https://www.mouser.co.uk/ProductDetail/Amphenol-Commercial-Products/124018402112A
https://www.lcsc.com/product-detail/span-style-background-color-ff0-USB-span-Connectors_G-Switch-GT-USB-7007A_C5299422.html

### LiPo Battery Charging
#### 1S
https://uk.rs-online.com/web/p/battery-management/7386360
https://www.mouser.co.uk/ProductDetail/Microchip-Technology-Atmel/MCP73832T-5ACI-OT
https://www.mouser.co.uk/datasheet/2/268/20001984g-846362.pdf

#### 2S
https://www.mouser.co.uk/ProductDetail/Microchip-Technology/MCP73844T-820I-MS

_This option needs regulator to 5v_

### Microcontroller Options
#### AtTiny85
- https://uk.farnell.com/microchip/attiny85-20su/mcu-8bit-attiny-20mhz-wsoic-8/dp/1455164
- Feels more "Haxxor" using a tiny processor
- More Difficult to implement
- The device achieves a throughput of 20 MIPS at 20 MHz and operates between 2.7 to 5.5V.
   - In voltage range 
- Have code almost ready to run https://github.com/Imogen-Wren-Studios/unicorn-attiny85

#### SAMD21
- 3.3v  MUST BE REGULATED
- Lots of experience with device
- https://www.mouser.co.uk/ProductDetail/Microchip-Technology/ATSAMD21E16L-AF?qs=9KdFJXLqUo%252B5fCZYsYcg9g%3D%3D

#### AtMega382p
- Most commonly understood platform - better engagement
- https://www.lcsc.com/product-detail/Microcontroller-Units-MCUs-MPUs-SOCs_Microchip-Tech-ATMEGA328P-AU_C14877.html
- Expensive
- in stock ATM
- 1.8 - 5.5v - No Need for Regulator
  - Qty.	Unit Price	Ext. Price
  - 1+	US  $3.045
  - 10+	US  $2.7126 - 	US$ 27.13

### ESP32
- 3v3 Only - needs regulating
- Wifiability gives further haxxor abilities
- OTA Updates
https://www.lcsc.com/product-detail/WiFi-Modules_Espressif-Systems-ESP32-WROOM-32-N4_C82899.html
- Have some code that could be used: https://github.com/Imogen-Wren-Studios/esp32-ws2812b-glediator
- Price: 
  - 1+   -  	US$3.2455	
  - 10+	 -   US$2.9273

### Capaciative Sensing

https://www.instructables.com/Capacitive-Sensing-for-Dummies/
_Seems to mostly be used with a microcontroller, havnt managed to find an analog audio implementation yet_

https://docs.arduino.cc/built-in-examples/analog/Smoothing Smoothing Data from Capacative touch sensor

## Edge Connector Idea

|Pin Num| label | use | notes |
|---    |---    |---  |---    |
| 0     |       |     |       |    
| 0     |       |     |       |    
| 0     |       |     |       |    
| 0     |       |     |       |    
| 0     |       |     |       |    
| 0     |       |     |       |    
| 0     |       |     |       |  


## Continued Development

Now the project has become more clearly defined, it is an ESP development board with built in WS2821b LEDs designed to be used as a wearable badge, or a light up stand
for 3D printing projects. It contains mounting tabs to assit in adding diffusers and optics. The wifi can be used to coordinate groups of them to sync colours around the room.

Given this I need a name for this development board. I was out of ideas so I asked Chat GPT and this is the current shortlist, some have been modified slightly or added to as this gave me ideas:

### Name Ideas:
- ESPuino
- DevSparkie
- Sparkino
- ESP-Firefly
- FaerFly
- Faer
- Luino
- Comet
- LEDirector
- Glimmerino
- ChromaCore
- PixelPilot
- PixelESP
- ChromaPilot
- Chromino
- illuminuno
- illumuino
- IlluminESP
- Illumin8
- Ilumin8
- Lumin8
- Lumin32
- Luminino
- Lumino32
- Luino32
- Jeff



