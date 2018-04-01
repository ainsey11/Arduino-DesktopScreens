#include <SPI.h>
#include <Ethernet.h>
#include <Wire.h>
#include "LCD.h"
#include "LiquidCrystal_I2C.h"

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
char server[] = "172.16.2.40";
IPAddress ip(172, 16, 2, 200);
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
LiquidCrystal_I2C  lcd(I2C_ADDR,En_pin,Rw_pin,Rs_pin,D4_pin,D5_pin,D6_pin,D7_pin);

void setup() {
	lcd.begin (16,2);
	Serial.begin(9600);
	while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
	if (Ethernet.begin(mac) == 0) {
		Serial.println("Failed to configure Ethernet using DHCP");
		Ethernet.begin(mac, ip);
	}
  delay(1000);
  Serial.println("connecting...");

if (client.connect(server, 80)) {
	Serial.println("connected");
    client.println("GET /arduinotest.txt");
    client.println("Host: 172.16.1.40");
    client.println("Connection: close");
    client.println();
  } else {
    Serial.println("connection failed");
	lcd.home();
	lcd.clear();
	lcd.setcursor(0,1);
	lcd.print("Connection Failed");	
  }
}
void loop() {
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
	lcd.home();
	lcd.clear();
	lcd.setcursor(0,1);
	lcd.print(c);
	delay(100);
  }
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    while (true);
  }
}