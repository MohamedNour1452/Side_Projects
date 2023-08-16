#include "MdioHeader.h"
#include "H7SegHeader.h"
#include <util/delay.h>


int main()
{
  SSegInit();
  u8 cnt = 20;
  SetPortDir(PC,OUTPUT);
  SetPortDir(PD,OUTPUT);
  while(1)
  {  
    if(cnt <= 20 && cnt > 0)
    {   
        SetPinValue(PD,pin3,LOW);
        SetPinValue(PC,pin2,HIGH);
        for(u8 i = 0; i<100;i++)
        { 
         if(cnt <= 10 && cnt%2 == 0)
        {
          SetPinValue(PC,pin7,HIGH);
        }
        else{}
          Set7segVal(cnt/10,cnt%10); 
          SetPinValue(PC,pin7,LOW);
        }
        cnt--;
    }
    else if(cnt == 0)
    {
      for(u8 i = 0; i < 100;i++)
      {
        SetPinValue(PD,pin3,HIGH);
        SetPortValue(PC,LOW);
        Set7segVal(0,0);
      }
      cnt = 20;
    }
  }
  return 0;
}
