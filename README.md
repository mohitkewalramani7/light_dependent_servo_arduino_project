# Title : light_dependent_servo_arduino_project

# Description :

A project written in C, which is written using the Arduino IDE, and used to programme the Arduino Microcontroller. This project involves setting up a sequential circuit on a solderless breadboard. Which connects a 5V power supply to a resistor. Connected in series is a light-dependent resistor (photoresistor). Based on the light emitted on the photoresistor, the resistance accross the initial resistor will decrease, allowing more current to flow through the circuit.

There are 2 parts to this project:

1) Based on the light emitted on the photoresistor, a 9G servo motor would accordingly rotate. When there is a high intensity of light emitted on the photoresistor, the 9G servo motor would rotate with high speed. When there is a low intensity of light, the 9G servo motor would rotate with a lesser speed. The speed of the 9G servo motor is controlled by delay commands, which are inserted in between each degree advancement of the servo's rotation. A low speed would result in a high delay for each rotation degree of the servo motor and vice-versa. The rotate method is included in the loop() function, so after each iteration of the motor, it will check to see the value that is generated using the photoresistor will be used as the new delay for the 9G Servo to rotate with.

2) An LCD display is also a part of the project. Once the script decides the time by which each degree rotation the 9G servo will be delayed for, it also outputs the delay time to the LCD for the user to see. An example would be "rotation delayed by 9ms" (9 milliseconds). Furthermore, the brightness of the LCD display is controlled by the use of a photoresistor.

# Viewing The Project:

The attached pictures and video links can be used to see the project in action.
