#include <Wire.h>
#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...


TMRpcm tmrpcm;   // create an object for use in this sketch

int old_ACW=0;

int Speed = 0;
int Old_speed = 83;
int SteeringAngle = 0;


int AudioCommandWord=0;

struct MultiBtnBitFieldType {
  bool MultiBlueBtn:1;
  bool MultiWhiteBtn:1;
  bool MultiYellowBtn:1;
  bool MultiRedBtn:1;
  bool MultiOrangeBtn:1;
  bool MultiGreenBtn:1;
  bool MultiGrayBtn:1;
  bool MultiBlackBtn:1;
};

union MultiBtnCharType {

  MultiBtnBitFieldType MultiBtnBitField;
  char MultiBtnByte;
} MultiBtnRcvChar;

void receiveEvent(int CommandWord)
{
  while(1 < Wire.available()){
    CommandWord = Wire.read();
    AudioCommandWord = CommandWord;
    MultiBtnRcvChar.MultiBtnByte = (char) CommandWord;
    SteeringAngle = Wire.read();
  }
  Speed = Wire.read();  
 
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

  static bool startup=true; 

  if (startup) {
    startup = false;
    tmrpcm.play("gt40.wav");
  }

  if ((AudioCommandWord > 0) && (AudioCommandWord!=old_ACW)) {
    if (MultiBtnRcvChar.MultiBtnBitField.MultiBlackBtn) {
      tmrpcm.play("gt40.wav");
      }
  if (MultiBtnRcvChar.MultiBtnBitField.MultiGrayBtn) {
    //tmrpcm.play("amb_conv.wav");
    }
  if (MultiBtnRcvChar.MultiBtnBitField.MultiGreenBtn) {
    //tmrpcm.play("ambh_conv.wav");
    }
  if (MultiBtnRcvChar.MultiBtnBitField.MultiOrangeBtn) {
    //tmrpcm.play("ambul_conv.wav");
    }
  if (MultiBtnRcvChar.MultiBtnBitField.MultiRedBtn) {
    //tmrpcm.play("car+alarm_conv.wav");
    }
  if (MultiBtnRcvChar.MultiBtnBitField.MultiYellowBtn) {
    //tmrpcm.play("car+geardown_conv.wav");
    }
  if (MultiBtnRcvChar.MultiBtnBitField.MultiWhiteBtn) {
    //tmrpcm.play("carhorn_conv.wav");
    }
  if (MultiBtnRcvChar.MultiBtnBitField.MultiBlueBtn) {
    //tmrpcm.play("lighter_conv.wav");
    }
  }

  if ((SteeringAngle > 130) || (SteeringAngle <50)) {
    tmrpcm.play("gt40.wav");
  }

  if (Speed < (Old_speed -2)) {
    //tmrpcm.play("gt40.wav");
  }

  old_ACW=AudioCommandWord; 
  return;   // don't do anything more if not

  

}
