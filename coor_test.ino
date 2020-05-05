
void setup() {
  Serial.begin(9600);
  
}

byte data[4];
float humidity = 0;
float temp = 0;
int co2 = 0;
char value[3] = {'h', 't', 'c'};
int i = 0;

void loop() {
  long seconds = millis();
  Serial.print(value[i]);
  while(Serial.available() != 4){
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
      Serial.print(i);
      Serial.print(": ");
      Serial.println(temp);
     }
     else {
      co2 = byteToInt(data);
      Serial.print(i);
      Serial.print(": ");
      Serial.println(co2);
     }
    
     i++;
     if(i == 3) i = 0;
  }
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
