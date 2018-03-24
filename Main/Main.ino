#include <SPI.h>
#include <Ethernet.h>
#include <LiquidCrystal.h>
#include <Wire.h>


// Random Mac address
byte mac[] = {
  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02
};

//Start Ethernet client up
EthernetClient client;

//Init LCD1
LiquidCrystal lcd(0x3F);



void setup() {
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

  // LCD
  lcd.begin(16,2);
  lcd.clear();
  lcd.print("Test1");
}

void loop() {

}
