#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <SoftwareSerial.h>
/**********************************************************/
LiquidCrystal_I2C lcd(0x3F, 16, 2); // set the LCD address to 0x3F for a 16 chars and 2 line display
SoftwareSerial xbee(3, 2); //3 = RX PIN, 2 = TX PIN
/*********************************************************/
void setup()
{
  Serial.begin(9600); // Initialize Serial Monitor
  xbee.begin(9600); //initialize Xbee serial
  lcd.init(); //initialize the lcd
  lcd.backlight(); //open the backlight
  
  lcd.print("RAIN MONITOR IS"); //Welcome message
  lcd.setCursor(0,1);
  lcd.print("NOW ONLINE");
}
/*********************************************************/
void loop()
{
  if (xbee.available() > 0) // If there is data..
  {
    char data = xbee.read(); // Store the data..

    if (data == '1') // If data is equal to 1
    {
      Serial.println("RAIN LEVEL: HIGH");
      lcd.clear(); 
      lcd.print("RAIN LEVEL: HIGH"); // Print HIGH
    }
    else if (data == '2') //else if data == 2
    {
      Serial.println("RAIN LEVEL: LOW");
      lcd.clear(); 
      lcd.print("RAIN LEVEL: LOW"); // Print LOW
    }
    
    delay(100);
  }
}
/************************************************************/

