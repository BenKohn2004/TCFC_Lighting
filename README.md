Fencing Scoring Light Relay System
Overview
This project provides an affordable, customizable light relay system for fencing scoring machines using off-the-shelf components. Unlike commercial repeater lights—which are often expensive and lack character—this solution is designed to be:

Low-cost: Uses components that can be sourced for under $100 total.

Easily built and repaired: Designed with hobbyist-friendly tools and parts.

Versatile: Allows creative freedom to match the aesthetic and spirit of your fencing club.

By investing a little time and care into setup, you can create a distinctive and functional enhancement for your fencing environment.

Project Summary
Two ESP8266 Wemos D1 Mini boards are used to interpret and relay scoring data:

Transmitter ESP8266: Reads output from a Favero scoring machine and sends it via Wi-Fi.

Receiver ESP8266: Receives data and activates relays to power lights corresponding to the scoring signals.

This setup is designed to be simple, functional, and adaptable to a variety of LED lights and power supplies.

Hardware Requirements
2x Wemos D1 Mini ESP8266

⚠️ Important: The board parsing the scoring machine output must use a CH340 chip. Other USB-to-serial chips may not work reliably with this setup.

4-Channel Relay Module(https://www.aliexpress.us/item/2261799814354583.html)

RJ11 Cable for connecting to the Favero output
RJ11 example

100Ω Resistor between Wemos ground and RJ11 ground pin
Resistor example

LEDs and power supplies (user's choice based on setup needs)

Note: The Favero machine internally connects the outer and inner RJ11 pins. Accidental wire flipping should not affect performance.

Schematics & Code
Wiring Diagram: Schematic_Favero_Parser_and_Receiver.pdf

Transmitter Code:
8266_Parser_and_Transmitter_Faster_Retransmit_TCFC
(Compiled using Arduino IDE)

Receiver Code:
8266_Receiver_Strip_Lights_Four_Relay
(Compiled using Arduino IDE)

Philosophy
This system was created to be a low-cost, character-rich alternative to sterile commercial solutions. By using common components and open designs, clubs can create repeater lights that reflect their unique identity—whether that means stylish LED strips, themed enclosures, or creative mounting.

With thoughtful planning and a small budget, this setup can bring professional-quality functionality to grassroots fencing spaces.

