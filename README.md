# imogen-wren-card-pcb
 Imogen Wren Business Card PCB
 ![219247000-73f04fbc-c211-4d27-b16b-3aa29c612e1f](https://user-images.githubusercontent.com/97303986/219356691-89f45db1-a097-4393-ae52-ee139121f84c.png)



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
 
 
 ## Circuit Snippets
 
 ### WS2821b LED Implementation
 
 ![image](https://user-images.githubusercontent.com/97303986/219457981-92afcb83-094e-4cd9-8534-0c05b1694e8a.png) <br>
https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf
- Vdd = 3.5 - 5.6 
- Vinput = VDD +-0.5



 Battery can be unregulated direct to LEDs & regulated to microcontroller
Slot for 2nd regulator for powering with 2s? or KISS

I think KISS


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

#### 2S
https://www.mouser.co.uk/ProductDetail/Microchip-Technology/MCP73844T-820I-MS

_This option needs regulator to 5v_



### Capaciative Sensing

https://www.instructables.com/Capacitive-Sensing-for-Dummies/
_Seems to mostly be used with a microcontroller, havnt managed to find an analog audio implementation yet_

https://docs.arduino.cc/built-in-examples/analog/Smoothing Smoothing Data from Capacative touch sensor
