# Arduino-RFID-TAG-SECURITY
Using RFID tags to gain access to systems involving servo motors that can be manipulated using servo motors (only one motor is used for this project)

Required Equipment :
- 1 servo motor with 180 degrees arm rotation and atleast 5 kg cm arm.
- arduino mega 2560 board.
- jumper wires
- active buzzer
- green LED
- red LED
- RFID Tag
-RFID Key card
-RFID MFRC522 module

wiring instructions:
- the wiring instructions are best described using the link https://www.youtube.com/watch?v=hxQYIwdZRng note that these wiring instructions are limited to an arduino mega2560 board.
-make sure to connect the buzzer to the right pin which can be identified from the define declaration, the same goes with the LEDS
-the potentiometer is connected to 5V , GND and A0.
-The servo motor is connected to the 5V pin on arduino for the red pin, the brown pin goes to GND, the orange pin goes to the respective pin in the IDE file.

Running Instructions:
-open the file using the arduino IDE.
-make sure you import the library MFRC522 from the include library in the IDE.
-edit the keyunlock_decimal array to match your RFID UID tag. I might update this later, but if I don't then this has to be entered manually. This is basically the UID of your tag in decimal and not hexadecimal. the value read is originally decimal not hexadecimal.
-make sure to connect the RC522 module correctly, just to be sure, run a firmware check from the examples in the library, this should return a status of okay. If it doesn't, check your wiring and try again.

- once you run the program. the system will initiate, and you will have to bring the tag that is meant to unlock the system close to the rfid module, the green LED should turn on and you should be able to gain access to manipulate the arm of the servo motor using the potentiometer that was wired previously.
-Note that any other RFID tag card will not work unless cloned to match the current RFID tag using EXTERNAL software.
