#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 5;


// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
SoftwareSerial ArduinoUno(3,2);
float lati, longi;

void setup()
{
  Serial.begin(115200);
  ss.begin(9600);
  ArduinoUno.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  ss.listen();
  displayInfo();

  ArduinoUno.listen();
  sendData();
  }

  void displayInfo(){
    Serial.println("Here to here uno port");
    while (ss.available() > 0){
    if (gps.encode(ss.read())){
      Serial.print(F("Location: ")); 
      if (gps.location.isValid())
      {
        Serial.println(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.println(gps.location.lng(), 6);
          }
      else
      {
        Serial.print(F("INVALID"));
      }
      }
    }
    }

void sendData(){
          ArduinoUno.listen();
          Serial.println("Listening to arduino uno port");
  while (ArduinoUno.available() > 0){
    Serial.println("Here to arduino uno port");
    int i = 10;
    ArduinoUno.print(i);
    ArduinoUno.println("\n");
    delay(1000);
      }
      }
