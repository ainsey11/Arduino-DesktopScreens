#include <SPI.h>
#include <Ethernet.h>

//Mac Address - Random Made one
byte mac[] = {  
  0xBE, 0xEF, 0x00, 0x00, 0xDE, 0x02 };

//Init Ethernet client lib
EthernetClient client;

void setup() {
  //start serial port up
  Serial.begin(9600);
  //start ethernet connection
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // no point in carrying on, so do nothing forevermore:
    for(;;)
      ;
}

Serial.println(Ethernet.localIP());


void loop() {
  // put your main code here, to run repeatedly:

}
