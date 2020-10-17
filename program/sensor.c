/*
*sensor.c
*/

#include "main.h"
#include "intrins.h"
#include "sensor.h"
void IRLaunch(unsigned char IR)
{
 int counter;
 if(IR=='L')//×ó±ß·¢Éä
   for(counter=0;counter<38;counter++)
    {
     SetLeftLaunch;
     _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
     _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
     ResetLeftLaunch;
     _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
     _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    }
  if(IR=='R')//ÓÒ±ß·¢Éä
    for(counter=0;counter<38;counter++)
    {
      SetRightLaunch;
      _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
      _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
      ResetRightLaunch;
      _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
      _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    }
}

_bool ReadLeftSensor(void){return (_bool)GetLeftIR;}
_bool ReadRightSensor(void){return (_bool)GetRightIR;}

_bool ReadLeftBeard(void){return (_bool)GetLeftBeard;}
_bool ReadRightBeard(void){return (_bool)GetRightBeard;}



