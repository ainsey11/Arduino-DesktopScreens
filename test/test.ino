#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h>
#include "LCD.h"
#include "LiquidCrystal_I2C.h"


// Random Mac address
byte mac[] = {
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
};

//Start Ethernet client up
EthernetClient client;


#define I2C_ADDR    0x3F // <<----- Add your address here.  Find it from I2C Scanner
#define BACKLIGHT_PIN     3
#define En_pin  2
#define Rw_pin  1
#define Rs_pin  0
#define D4_pin  4
#define D5_pin  5
#define D6_pin  6
#define D7_pin  7

int n = 1;

LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup()
{
  // Start LCD
  lcd.begin (16,2); //  <<----- My LCD was 16x2
  
  // start the serial library:
  Serial.begin(9600);
  // start the Ethernet connection:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for (;;)
      ;
  }
// print your local IP address:
Serial.println(Ethernet.localIP());
  
// Switch on the backlight
lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
lcd.setBacklight(HIGH);
lcd.home (); // go home
lcd.print("Local IP is:");
lcd.setCursor (0,1); 
lcd.print(Ethernet.localIP());  
}

void loop()
{
}
