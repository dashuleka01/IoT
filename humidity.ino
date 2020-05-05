
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
byte ddata[4];

void setup() {
   Serial.begin(9600);
   dht.begin();
}


void loop() {
   if (Serial.available() > 0) {
    char u = Serial.read();
    if(u == 'h') {
      float hh = dht.readHumidity();
      floatToByte(hh, ddata);
      Serial.write(ddata, 4); 
    }
    else if(u == 't') {
      floatToByte(dht.readTemperature(), ddata);
      Serial.write(ddata, 4);
    }
   }
}


void floatToByte(float value, byte data[]){
  int val = value * 100;

  data[0] = (byte) ((val & 0xFF000000) >> 32);
  data[1] = (byte) ((val & 0x00FF0000) >> 16);
  data[2] = (byte) ((val & 0x0000FF00) >> 8);
  data[3] = (byte) (val & 0x000000FF);
}
