void setup() {
  Serial.begin(9600);
}

char command;

void loop() {
  while(Serial.available() > 0){
    command = Serial.read();
    switch(command) {
    case 'i':
      Serial.print('3');
      break;
    
    case 'c':
      Serial.print('4');
      break;
    
    default:
      break;
    }
  }
}
