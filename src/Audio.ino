#include <Wire.h>
#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...


TMRpcm tmrpcm;   // create an object for use in this sketch

int old_ACW=0;


int AudioCommandWord=0;


void receiveEvent(int CommandWord)
{
  while(Wire.available()){
    CommandWord = Wire.read();
    AudioCommandWord = CommandWord;
    Serial.println(CommandWord);
  }	
}

void setup() {
 Serial.begin(115200);
 Serial.println("Start");

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


 if ((AudioCommandWord == 1) && (AudioCommandWord!=old_ACW)) {
  Serial.print("Playing:");
  
  tmrpcm.play("gt40.wav");
  }
  old_ACW=AudioCommandWord; 
  return;   // don't do anything more if not


}
