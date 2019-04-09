# AirMini
Airwire Pro Mini 328p

This is an Arduino Sketch intended for the 5v 16Mhz ProMini. It is written in C, not Arduino C++. It allows you to monitor the data coming in from the T5000 Airwire transmitter. Nothing is done with the data in this sketch except to output completed hex packets to the serial port. This allows you to watch what is flowing over the air. With a bit of research you can intercept these packets and (possibly) do interesting things with them.

This board outputs logic level DCC received by the CC1101 modem component.  To drive decoders you will need something like my DCC Amplifier which is based on a LN298 motor driver chip (available from Sparkfun) to boost the logic level DCC up to whatever voltage you are running at. I generally use a 14.8v Lipo.
