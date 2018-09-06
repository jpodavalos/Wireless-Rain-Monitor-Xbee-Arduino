# Wireless-Rain-Monitoring-Xbee-Arduino
A simple wireless rain monitoring system that is compose of one Xbee for transmitting and one for receiving. When the rain sensor outputs digital HIGH, it will be sent to the receiving Xbee and will send an SMS to the indicated phone number.

## Hardware Requirements
* 1 LCD with I2C driver
* 2 Xbee S2C 
* 1 GSM SIM 900 Module 
* 2 Arduino

## Software Requirements
* Arduino IDE
* GSM 900 Library
* LCD i2c library 


## Need to change at Rain Monitor TX
```
const char *phone_number = "09999999"; //Receiver's phone number
```


## References:
* http://www.geeetech.com/wiki/index.php/Arduino_GPRS_Shield
* https://www.elecrow.com/wiki/index.php?title=XBee_shield
* http://www.hobbytronics.co.uk/xbee-s2c-configuration
