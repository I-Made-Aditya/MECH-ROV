/* RC CAR, Translated from Bluetooth Amazon Car to work with Arduino Mega, Flysky FS-I6X Controller and Receiver and Adafruit Motor Shield v2.3

  Special thanks to Youtube Channel "DroneBot Workshop" for providing a Template for the Code - https://dronebotworkshop.com/radio-control-arduino-car/
  Channel functions by Ricardo Paiva - https://gist.github.com/werneckpaiva/

  Written by Enrique Lopez - reference "https://enriquelopezcode.github.io/projects/rc_car" and click on the Arduino Projects Hub link for required parts and wiring  */

//Include Libraries
#include <Wire.h>

#include <IBusBM.h>

//MOTOR A
#define pwmA 6
#define in1A 2
#define in2A 3
//MOTOR B
#define pwmB 5
#define in1B 4
#define in2B 7
//MOTOR C
#define pwmC 9
#define in1C 8
#define in2C 11
//MOTOR D
#define pwmD 10
#define in1D 12
#define in2D 13


// Create iBus Object and Channel Values
IBusBM ibus;

int rcCH1 = 0;  // Left - Right
int rcCH2 = 0;  // Maju
int rcCH3 = 0;  // Speed
int rcCH6 = 0;  // Nyelam

//Motor Speed Variables
int motor1speed = 0;
int motor2speed = 0;
int motor3speed = 0;
int motor4speed = 0;

//Motor Direction variables
int motor1dir = 0;
int motor2dir = 0;
int motor3dir = 0;
int motor4dir = 0;

// Read the number of a given channel and convert to the range provided.
// If the channel is off, return the default value (by Ricardo Paiva)
int readChannel(byte channelInput, int minLimit, int maxLimit, int defaultValue) {
  uint16_t ch = ibus.readChannel(channelInput);
  if (ch < 100) return defaultValue;
  return map(ch, 1000, 2000, minLimit, maxLimit);
}

bool readSwitch(byte channelInput, bool defaultValue) {
  int intDefaultValue = (defaultValue) ? 100 : 0;
  int ch = readChannel(channelInput, 0, 100, intDefaultValue);
  return (ch > 50);
}


// Control Motor 1
void mControl1(int mspeed, int mdir) {
  analogWrite(pwmA, mspeed);
  if (mdir == 1) {
    // Motor forward
    digitalWrite(in1A, HIGH);
    digitalWrite(in2A, LOW);
  } else {
    // Motor backward
    digitalWrite(in1A, LOW);
    digitalWrite(in2A, HIGH);
  }
}

// Control Motor 2
void mControl2(int mspeed, int mdir) {
  analogWrite(pwmB, mspeed);
  if (mdir == 1) {
    // Motor forward
    digitalWrite(in1B, HIGH);
    digitalWrite(in2B, LOW);
  } else {
    // Motor backward
    digitalWrite(in1B, LOW);
    digitalWrite(in2B, HIGH);
  }
}

void mControl3(int mspeed, int mdir) {
  analogWrite(pwmC, mspeed);
  if (mdir == 1) {
    // Motor forward
    digitalWrite(in1C, HIGH);
    digitalWrite(in2C, LOW);
  } else {
    // Motor backward
    digitalWrite(in1C, LOW);
    digitalWrite(in2C, HIGH);
  }
}
void mControl4(int mspeed, int mdir) {
  analogWrite(pwmD, mspeed);
  if (mdir == 1) {
    // Motor forward
    digitalWrite(in1D, HIGH);
    digitalWrite(in2D, LOW);
  } else {
    // Motor backward
    digitalWrite(in1D, LOW);
    digitalWrite(in2D, HIGH);
  }
}

void setup() {
  //Call begin on Motorshield Object and Delay for Connection
  Serial.begin(115200);
  ibus.begin(Serial);

  pinMode(pwmA, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);

  pinMode(pwmB, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);

  pinMode(pwmC, OUTPUT);
  pinMode(in1C, OUTPUT);
  pinMode(in2C, OUTPUT);

  pinMode(pwmD, OUTPUT);
  pinMode(in1D, OUTPUT);
  pinMode(in2D, OUTPUT);

}

void loop() {
  //Get Channel Values
  rcCH1 = readChannel(0, -100, 100, 0); // kanan kiri
  rcCH2 = readChannel(1, -100, 100, 0); //maju mundur
  rcCH3 = readChannel(2, 0, 155, 0); // speed
  //  rcCH5 = readChannel(4, -100, 100, 0);
  rcCH6 = readSwitch(5, false); //Nyelam

  //Motor Speeds Channel 3
  motor1speed = rcCH3;
  motor2speed = rcCH3;
  motor3speed = rcCH3;
  motor4speed = rcCH3;

  if (rcCH6 == 1) {
    //MODE PROPELLER ATAS
    if (rcCH2 >= 0) {
      //NYELAM
      motor3dir = -1;
      motor4dir = -1;
    } else {
      //NAIK
      motor3dir = 1;
      motor4dir = 1;
    }
    //ABSOLUTE TAMBAH SPEED
    motor3speed = motor3speed + abs(rcCH2);
    motor4speed = motor4speed + abs(rcCH2);
  } else {
    //MODE PROPPELER BELAKANG
    if (rcCH2 >= 0) {
      //MAJU
      motor1dir = -1;
      motor2dir = -1;
    } else {
      //MAJU
      motor1dir = 1;
      motor2dir = 1;
    }
    //ABSOLUTE TAMBAH SPEED
    motor1speed = motor1speed + abs(rcCH2);
    motor2speed = motor2speed + abs(rcCH2);
  }

  // SET BELOK KANAN KIRI
  motor1speed = motor1speed + rcCH1;
  motor2speed = motor2speed - rcCH1;
  //  motor3speed = motor3speed - rcCH1;
  //  motor4speed = motor4speed - rcCH1;

  // Ensure that speeds are between 0 and 255
  motor1speed = constrain(motor1speed, 0, 255);
  motor2speed = constrain(motor2speed, 0, 255);
  motor3speed = constrain(motor3speed, 0, 255);
  motor4speed = constrain(motor4speed, 0, 255);

  //Drive Motors
  mControl1(motor1speed, motor1dir);
  mControl2(motor2speed, motor2dir);
  mControl3(motor3speed, motor3dir);
  mControl4(motor4speed, motor4dir);
  //small delay
  delay(50);
}
