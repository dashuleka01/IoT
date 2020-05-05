
void setup() {
  Serial.begin(9600);
  delay(1000);
}

byte data[4];
float humidity = 0;
float temp = 0;
int co2 = 0;
char value[] = {'h', 't'};
int i = 0;

void loop() {

 
  Serial.print(value[i]);
  while(Serial.available() != 4){}
  if (Serial.available() == 4){
     data[0] = Serial.read();
     data[1] = Serial.read();
     data[2] = Serial.read();
     data[3] = Serial.read();
     temp = byteToFloat(data);
     Serial.print(i);
     Serial.print(": ");
     Serial.println(temp);
     
     i++;
     if(i == 2) i = 0;
  }
  delay(3000);

  /*Serial.print('c');
  while (Serial.available() == 4){
     data[0] = Serial.read();
     data[1] = Serial.read();
     data[2] = Serial.read();
     data[3] = Serial.read();
     co2 = byteToInt(data);
     Serial.print(co2);
  }
  delay(1000);

  Serial.print('h');
  if (Serial.available() > 0){
     data[0] = Serial.read();
     data[1] = Serial.read();
     data[2] = Serial.read();
     data[3] = Serial.read();
     Serial.print("kek2 ");
     humidity = byteToFloat(data);
     
     Serial.println(humidity);
  }
  delay(1000);*/
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
