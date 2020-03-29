#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>

SoftwareSerial NodeMCU(D2,D3);

void setup(){
	Serial.begin(115200);
	NodeMCU.begin(115200);
	pinMode(D2,INPUT);
	pinMode(D3,OUTPUT);
}

void loop(){
	int i = 10;
	NodeMCU.print(i);
	NodeMCU.println("\n");
	delay(1000);

 while(NodeMCU.available()>0){
  float val = NodeMCU.parseFloat();
  if(NodeMCU.read()== '\n'){
  Serial.println(val);
  }
}
}
