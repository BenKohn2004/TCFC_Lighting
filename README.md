This project uses two ESP8266 Wemos D1 Minis to receive output data from a Favero scoring machine and then relay it to another ESP8266 via wifi which will then activate relays to corresponding to the lights on the fencing box.

Of note, ESP8266 Wemos D1 Mini that is used to parse the output data from the scoring machine must be a specific version, specifically it must use the CH340 chip.

https://www.aliexpress.us/item/3256806703939501.html?spm=a2g0o.order_list.order_list_main.5.58361802DW8CAm&gatewayAdapt=glo2usa

There are other ways to work around this, but using this specific chipset is the easiest and most straightforward. 
