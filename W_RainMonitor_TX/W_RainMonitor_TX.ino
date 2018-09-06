#include <GPRS_Shield_Arduino.h> //Library for SIM900 GPRS Shield
#include <SoftwareSerial.h> // Software Serial Communication using Digital Pin 7 and 8
#include <Wire.h> // Required for proper wire functions

//GSM Module variables
const int transmit_pin = 7; //Digital Pin 7 for TX
const int receive_pin = 8;  //Digital Pin 8 for RX
const int baudrate = 19200; //Speed of serial transfer, 19200 is the default
const char *phone_number = "09999999"; //Receiver's phone number

//Rain gauge variables
const short int rain_pin = 4; //Digital PIN #4 as the RAIN PIN
char *past_data; // Used to avoid flooding of data

GPRS activateGSM(transmit_pin, receive_pin, baudrate); // Activate GPRS Module function
SoftwareSerial xbee(3, 2); //Initailize Xbee Serial

void setup() {
  Serial.begin(19200);
  xbee.begin(9600);
  pinMode(rain_pin, INPUT); //Set rain pin #4 as input

  activateGSM.listen();
  //Check if GPRS module is working...
  while (!activateGSM.init()) // While not detected
  {
    delay(1000);
    Serial.println(F("Error initializing GSM Module. Please check if it is turned on."));
  }
  activateGSM.sendSMS(phone_number, " Wireless Rain Gauge Monitor is now online. Notifications will be received in case of changes."); //Send message that the everything is okay
  
  Serial.println(F("GSM initialization succesful!"));
  xbee.listen();
  delay(3000);
}

void loop() {

  char rain_pin_status = digitalRead(rain_pin); //Read the status of Digital Pin #4

  if (rain_pin_status == HIGH) //If it is high..
  {
    if (past_data != rain_pin_status)
    {
      xbee.write(49); //Send character '1'
      Serial.println("HIGH"); // Send HIGH
      past_data = HIGH;
      activateGSM.listen();
      activateGSM.sendSMS(phone_number, "Current Rain Level: HIGH"); //Send the message
      xbee.listen(); 
    }
  }
  else if (rain_pin_status == LOW) //Else if LOW
  {
    if (past_data != rain_pin_status)
    {
      xbee.write(50); //Send character '2'
      Serial.println("LOW"); // Send LOW
      past_data = LOW;
      activateGSM.listen();
      activateGSM.sendSMS(phone_number, "Current Rain Level: LOW"); //Send the message 
      xbee.listen();
    }
  }

  delay(100);
}
