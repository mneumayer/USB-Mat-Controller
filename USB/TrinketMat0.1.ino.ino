/*
ProTrinketKeyboard example
For Pro Trinket (ATmega328 based Trinket) by Adafruit Industries
Please use library TrinketKeyboard for the ATtiny85 based Trinket
Version 1.0  2015-01-01 Initial Version derived from TrinketKeyBoardExample  Mike Barela
*/
 
#include <ProTrinketKeyboard.h>  // Ensure the library is installed
 
// Switches are connected from ground to these defined pins
const int leftPad = 0;
const int rightPad = 2;
int lp = 0;
int rp = 0;
int lpflag = 0;
int lastlpflag = 0;
int rpflag = 0;
int lastrpflag = 0;
int limit = 880; // last (880) Force Sensing Resistor - 0-1000 lower = more sensitive 
int timedelay = 0; // freezes choice 
 
void setup()
{
pinMode(leftPad, INPUT);
pinMode(rightPad, INPUT);

 // start USB stuff
  TrinketKeyboard.begin();



}
 


void loop()
{
 
 String stringOne = "";
  
  TrinketKeyboard.poll();
  // the poll function must be called at least once every 10 ms
  // or cause a keystroke
  // if it is not, then the computer may think that the device
  // has stopped working, and give errors
 
lp = analogRead(leftPad);
rp = analogRead(rightPad);

if (lp > limit)
  {
  lpflag = 1; 
  }

if(lp < limit)
  {
   lpflag = 0;
   lastlpflag = 0;
  }

if(lpflag != lastlpflag)
  {
  
  
  stringOne = "a";
  //stringOne = "KEY_LEFT_ARROW";
 TrinketKeyboard.print("a");
  lastlpflag = lpflag;
  delay(timedelay);
  }

if (rp > limit)
  {
  rpflag = 1; 
  }

if(rp < limit)
  {
   rpflag = 0;
   lastrpflag = 0;
  }

if(rpflag != lastrpflag)
  {
  
  lastrpflag = rpflag;
  //stringOne = "KEY_RIGHT_ARROW";
  TrinketKeyboard.print("b");
  
  
  delay(timedelay);
 
  
  }
   
  }

