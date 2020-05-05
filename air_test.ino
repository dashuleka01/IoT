#include <SparkFunCCS811.h>
#include <Wire.h>

#define CCS811_ADDR 0x5B //Default I2C Address
//#define CCS811_ADDR 0x5A //Alternate I2C Address

CCS811 myCCS811(CCS811_ADDR);

int co2;
int tvoc;
byte ddata[4];
char command;

void setup()
{
    Serial.begin(9600);
    Wire.begin();
    myCCS811.begin();
}


void loop()
{
  if(Serial.available() > 0){
    command = Serial.read();
    if (myCCS811.dataAvailable() && command == 'c') {
        myCCS811.readAlgorithmResults();
        co2 = myCCS811.getCO2();
        intToByte(co2, ddata);
        Serial.write(ddata, 4);
    }
  }
}

void intToByte(int val, byte data[]){
  data[0] = (byte) ((val & 0xFF000000) >> 32);
  data[1] = (byte) ((val & 0x00FF0000) >> 16);
  data[2] = (byte) ((val & 0xFF00) >> 8);
  data[3] = (byte) (val & 0x00FF);
}
