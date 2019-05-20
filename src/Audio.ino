#include <Wire.h>
#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...


TMRpcm tmrpcm;   // create an object for use in this sketch
int SW1; 

int old_SW1=0;


int CommandWord=0;


void receiveEvent(int CommandWord)
{
  while(Wire.available()){
    CommandWord = Wire.read();
  }	
}

void setup() {
 Serial.begin(115200);
 Serial.println("Start");
 pinMode(A0,INPUT);  //Define A0 as digital input.
 tmrpcm.speakerPin = 9; //11 on Mega, 9 on Uno, Nano, etc
 
if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
  Serial.println("no SDCard");
  return;   // don't do anything more if not
} else Serial.println("SDCard is there");
 
tmrpcm.setVolume(5);
tmrpcm.volume(1);




  Wire.begin(9);
  Wire.onReceive(receiveEvent);
}




void loop() { 
 SW1=digitalRead(A0); 

 if ((SW1 == LOW) && (SW1!=old_SW1)) { //if SW1 pressed then play file "6.wav"
  Serial.print("Playing:");
  
  tmrpcm.play("gt40.wav");
  }
  old_SW1=SW1; 
  return;   // don't do anything more if not
}
