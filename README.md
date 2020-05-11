# AirMini
Airwire Pro Mini 328 RX/TX

This is an Arduino Sketch intended for the 5v 16Mhz ProMini and a CC1101 radio modem board. It allows you to 
either receive or transmit logic level DCC signals using the Airwire Protocol.

This sketch includes methods for decoding the Airwire bit stream and driving servos.

Channel setting and the mode (TX/RX) are in the main sketch as defines.

If you run this board in transmit mode, you will need an opto isolator circuit to translate the large voltage transistions of normal DCC into logic level.

In RX mode, you will need a DCC amplifier to boost the logic level DCC signal to full power DCC.

More info - http://blueridgeengineering.net/index.php/wiki/building-the-promini-air/
