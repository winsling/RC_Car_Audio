//www.elegoo.com
//2016.12.9

//We always have to include the library
#include "LedControl.h"
#include <Wire.h>

/*
 Now we need a LedControl to work with.
 ***** These pin numbers will probably not work with your hardware *****
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 We have only a single MAX72XX.
 */
LedControl lc=LedControl(12,10,11,1);

int FrontLight=0;

unsigned long delaytime1=50;
unsigned long delaytime2=200;


void receiveEvent(int FrontLight)
{
  while(Wire.available()){
    FrontLight = Wire.read();
  }	

  digitalWrite(2,FrontLight);
}



void setup() {
  /*
    Der MAX72XX ist im Power-Save-Modus beim Start,
    Wir müssen einen "Weckruf" machen
   */
  lc.shutdown(0,false);
  /* Set the brightness to a medium values */
  lc.setIntensity(0,8);
  /* and clear the display */
  lc.clearDisplay(0);
  pinMode(2,OUTPUT);
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
}

/*
 Diese Methode zeigt die Zeichen für das
  Wort "Arduino" nacheinander auf der Matrix.
  (Du brauchst mindestens 5x7 LEDs, um die ganzen Zeichen zu sehen)
 */
void writeArduinoOnMatrix() {
  /*Hier sind die Daten für die Zeichen */
  byte a[8]={B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,B00000000};
  byte b[8]={B00000000,B00000000,B00000000,B00011000,B00011000,B00000000,B00000000,B00000000};
  byte c[8]={B00000000,B00000000,B00111100,B00111100,B00111100,B00111100,B00000000,B00000000};
  byte d[8]={B00000000,B01111110,B01111110,B01111110,B01111110,B01111110,B01111110,B00000000};
  byte e[8]={B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
  
  /* Zeigen sie nun eins nach dem anderen mit einer kleinen Verzögerung an */
  for (int i=0;i<8;i++) {
    lc.setRow(0,i,a[i]);
  };
  delay(delaytime1);
  for (int i=0;i<8;i++) {
    lc.setRow(0,i,b[i]);
  };
  delay(delaytime1);
  for (int i=0;i<8;i++) {
    lc.setRow(0,i,c[i]);
  };
  delay(delaytime1);
  for (int i=0;i<8;i++) {
    lc.setRow(0,i,d[i]);
  };
  delay(delaytime1);
  for (int i=0;i<8;i++) {
    lc.setRow(0,i,e[i]);
  };
  delay(delaytime1);
  for (int i=0;i<8;i++) {
    lc.setRow(0,i,d[i]);
  };
  delay(delaytime1);
  for (int i=0;i<8;i++) {
    lc.setRow(0,i,c[i]);
  };
  delay(delaytime1);  
  for (int i=0;i<8;i++) {
    lc.setRow(0,i,b[i]);
  };
  delay(delaytime1);}



void loop() { 
  
  writeArduinoOnMatrix();
  
  
}
