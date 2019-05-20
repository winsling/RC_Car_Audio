#include <Wire.h>


int CommandWord=0;


void receiveEvent(int CommandWord)
{
  while(Wire.available()){
    CommandWord = Wire.read();
  }	
}

void setup() {

  Wire.begin(9);
  Wire.onReceive(receiveEvent);
}




void loop() { 
  
  
  
}
