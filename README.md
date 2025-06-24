This project uses two ESP8266 Wemos D1 Minis to receive output data from a [Favero scoring machine] (https://www.favero.com/en2_fencing_sport_electronic_scoreboard_fencing_signalling_equipment_apparatus_for_foil_sword_epee_sabre-29-17.html) and then relay it to another ESP8266 via wifi which will then activate relays to corresponding to the lights on the fencing box.

Of note, ESP8266 Wemos D1 Mini that is used to parse the output data from the scoring machine must be a specific version, specifically it must use the [CH340 chip] (https://www.aliexpress.us/item/3256806703939501.html). There are other ways to work around this, but using this specific chipset is the easiest and most straightforward. 

The electrical connections can be seen on [Schematic_Favero_Parser_and_Receiver](Schematic_Favero_Parser_and_Receiver.pdf). The code for the Transmitter was compiled on the Arduino IDE with the parser code being [8266_Parser_and_Transmitter_Faster_Retransmit_TCFC](8266_Parser_and_Transmitter_Faster_Retransmit_TCFC) and the receiver code being [8266_Receiver_Strip_Lights_Four_Relay](8266_Receiver_Strip_Lights_Four_Relay).

The philosophy of the project is to use cheap, of the shelf, easily built and easily repairable components. At some point in the future, I may build a PCB to facilitate the wiring, but as of now I just use wires.

The size of the Favero data output is [RJ11] (https://www.aliexpress.us/item/3256807761034393.html) and a [100 ohm resistor] (https://www.aliexpress.us/item/3256806360281394.html) is required between the ground of the Wemos board and the ground pin for the RJ11 connections. The outside and inside connections for the RJ11 are actually connected within the Favero scoring machine, so flipping the wires upside down by accident, should not cause any noticeable affect on the operation.

