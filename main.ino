/**
 * The Arduino sketch that declares the setup
 * and loop methods that will be programmed into
 * the microcontroller
 * 
 * @author Mohit Kewalramani
 * @version 1.0
 * @published 2017-06-24
 */

#include <Servo.h>
#include <LiquidCrystal.h>

/*
The pin on the Arduino that reads the analog value of the 
resistance accross the circuit containing the light-dependent resistor
*/
int lightSensor = A0;

// The output pin to which the Servo is connected
int servoPin = 3;

Servo servo;
LiquidCrystal lcd(12, 11, 7, 6, 5, 4);  // Initializes the pins that control the LCD

/**
 * The method that occurs once at the start of the run to set
 * up the pins and establish the initial configuration
*/
void setup() {
    pinMode(lightSensor, INPUT);      // Initializes the lightSensor (A0) to be input variable
    pinMode(servoPin, OUTPUT);        // Initializes the servoPin (3) to be output variable
    servo.attach(3);                  // Attaches the servo to pin 3
    lcd.begin(16,2);                  // Initializes the LCD to have 16 columns, 2 rows
}

/**
 * The method that occurs repeatedly while the microcontroller is supplied
 * with power. This method runs after the setup has ran.
*/
void loop() {
    // Reads in the resistance value of from the light-dependent resistor circuit
    int lightSensorValue = analogRead(lightSensor); 
    
    // Constrains the value to a value between 100 and 700
    int range = constrain(lightSensorValue, 100, 700);
    
    // Calls the helper method to decide the time by which to delay the Servo rotation
    int delayTimeValue = delayTime(range);
    
    // Go to first row of LCD and print the output heading
    lcd.setCursor(0, 0);
    lcd.print("Delay Rotation");
    
    // Go to second row of LCD and print the time by which the Servo rotation is delayed
    lcd.setCursor(0, 1);
    lcd.print("By " + String(delayTimeValue) + " ms ");
    
    // Based on delay time, accordingly rotate the Servo
    rotateServo(delayTimeValue);
}