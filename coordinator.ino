
void setup() {
  //Serial.begin(9600);
}

byte data[4];
float humidity = 0;
float temp = 0;
int co2 = 0;
char value[3] = {'h', 't', 'c'};
int i = 0;

void loop() {
  Serial.begin(9600);
  long seconds = millis();
  Serial.print(value[i]);
  int j = 0;
  while(Serial.available() < 4){
    if(millis() - seconds >= 1000){
      seconds = millis();
      Serial.print(value[i]);
    }
  }
  
  if (Serial.available() == 4){
     data[0] = Serial.read();
     data[1] = Serial.read();
     data[2] = Serial.read();
     data[3] = Serial.read();
     if(i <= 1){
      temp = byteToFloat(data);
      Serial.print(": ");
      Serial.print(temp);
      checkParameters(temp, i);
     }
     else {
      co2 = byteToInt(data);
      Serial.print(": ");
      Serial.print(co2);
      checkParameters(co2);
     }
    
     i++;
     if(i == 3) i = 0;
  }
  Serial.end();
  delay(3000);

}

float byteToFloat (byte data[]) {
  int val = ((int)(data[0]) << 32) + ((int)(data[1]) << 16) + ((int)(data[2]) << 8) + (int)(data[3]);
  float v = ((float) val) / 100;
  return v;
}

int byteToInt (byte data[]) {
  int val = ((int)(data[0]) << 32) + ((int)(data[1]) << 16) + ((int)(data[2]) << 8) + (int)(data[3]);
  return val;
}

void checkParameters(float par, int temp){
  if(temp == 1){
    if(par <= 21.0) Serial.println(" Temperature is too low");
    else if(par >= 25.0) Serial.println(" Temperature is too high");
    else Serial.println(" Temperature is good");
  }
  else {
    if(par <= 30.0) Serial.println(" Air is too dry");
    else if(par >= 50.0) Serial.println(" Air is too wet");
    else Serial.println(" Air is good");
  }
}

void checkParameters(int par) {
  if(par >= 1000) Serial.println(" CO2 concentration is too high");
  else Serial.println(" Everything is OK");
}

