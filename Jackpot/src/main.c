#include <MdioHeader.h>
#include <H7SegHeader.h>
#include <util/delay.h>
#include <time.h>

int main()
{
  label: SSegInit();
  srand(time(0));
  SetPinDir(PD,pin2,INPUT);
  SetPinDir(PD,pin3,OUTPUT);
  SetPinDir(PC,pin2,OUTPUT);
  SetPinDir(PC,pin7,OUTPUT);
  u16 x = 50 ;
  u8 num = 0;  
   while(ReadPinValue(PD,pin2) == 0)
    {
      num = (rand() % (99 + 1 + 1)) + 1; //generating random number between 1->99 using (rand() % (higherNum + lowerNum + 1)) + lowerNum
      for(u8 i = 0; i < 15; i++)
      {
        Set7segVal(num/10,num%10);
      }
    }
    if(ReadPinValue(PD,pin2) == 1)
    { 
      while(x<=200)  // making sure it takes 5 seconds x+x+x+x=50+100+150+200=500 * 10ms =5000 ms
      {
        num = (rand() % (99 + 1 + 1)) + 1;
        for(u16 i = 0; i < x; i++)
         { 
           Set7segVal(num/10,num%10);
         }
        x = x + 50;
      }
    }
    else{}
    if (num < 50) // first condition if you get a number lower than 50 you lose and the number stays on the screen for 5 second then the game starts over
    {
     for(u16 i = 0; i < 500; i++) // showing the number for 5 seconds
     {
       Set7segVal(num/10,num%10);
     }
      goto label; // starting over 
    }
    else if(num > 50) // second condition if you get a number higher than 50 you win and the number starts flashing for 5 seconds then the game starts over
    {
      u16 cnt = 0; 
      while(cnt <= 500)
      {
        label2: for(u8 i = 0; i < 50 ; i++)
        { 
          if(num == 77) // if you got the lucky number 77 the number and the leds flashs rapidly 
          {
          SetPinValue(PC,pin2,HIGH);
          SetPinValue(PC,pin7,HIGH);
          SetPinValue(PD,pin3,HIGH);
          }
          else{}
          Set7segVal(num/10,num%10);  
          SetPinValue(PC,pin2,LOW);
          SetPinValue(PC,pin7,LOW);
          SetPinValue(PD,pin3,LOW);
        }
          Set7segVal(SSOFF,SSOFF);
          _delay_ms(500);
          cnt += 100;
        }
        if(num == 77)
        {
          goto label2;
        }
        else
        {
        goto label;
        }   
    }

}
