#include <MeetAndroid.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// declare MeetAndroid so that you can call functions with it
MeetAndroid meetAndroid;
LiquidCrystal_I2C lcd(0x27,16,2); 
int Switch1 = 4;
int button;
int cod=0;
int tobeornottobe=0;
int bePressed=0;
int longtime=100000;

int brown1 = 6;
int brown2 = 7;
int green1 = 8;  
int green2 = 9;
int orange1 = 10;  
int orange2 = 11;
int blue1 = 12;
int blue2 = 13;

int per=1000;
int wait=1000; //1000=1s
int count=3; 
int i=0;

void setup() 
{     
  Serial.begin(9600);
   lcd.init();   // initialize the lcd 
  lcd.backlight();
  // register callback functions, which will be called when an associated event occurs.
  meetAndroid.registerFunction(green, 'o');
  meetAndroid.registerFunction(blue, 'p');  
  meetAndroid.registerFunction(ting, 'q'); 
  meetAndroid.registerFunction(brown, 'r');
  meetAndroid.registerFunction(orange, 's');    
  meetAndroid.registerFunction(all, 't');    
  meetAndroid.registerFunction(playall, 'u');   
    pinMode(green1, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(brown1, OUTPUT);
    pinMode(brown2, OUTPUT);
    pinMode(orange1, OUTPUT);
    pinMode(orange2, OUTPUT);
    pinMode(blue1, OUTPUT);
    pinMode(blue2, OUTPUT);
    pinMode(Switch1, INPUT);
} 
void loop() 
{ 
  if(tobeornottobe==0)
 {
 getinput();
 tobeornottobe++;
 }

}

void getinput()
{
   initlcd2();
  while(1)
  {
 button=pulseIn(Switch1,HIGH,10000000);
 if(button==0&&bePressed==0){break;}
 if(button!=0) {  pressed();bePressed++;}
 
  }  
 
 while(1)
 {
  meetAndroid.receive(); 
 }
 
}

void initlcd2()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("INPUT TIME VALUE:");
  lcd.setCursor(0,1);
  lcd.print(cod);
}

void pressed()
{
  if (cod==0){initlcd2();
             green('o','o');delay(longtime);
             cod++;
             
  }
  else if(cod==1){initlcd2();
                 blue('o','o');delay(longtime);
                  cod++;
                  
  }
  else if(cod==2){initlcd2();
                 orange('o','o');delay(longtime);
                  cod++;
                  
  }
  else if(cod==3){initlcd2();
                  brown('o','o');delay(longtime);
                  cod++;
                  
  }
  
  else if (cod!=0){ initlcd2();          
                   ting('o','o');
                   cod=0;
                  
  }
}

void ting(byte flag, byte numOfValues)
        {
          digitalWrite(green1,LOW);   
          digitalWrite(green2,LOW);
          digitalWrite(brown1,LOW);   
          digitalWrite(brown2,LOW);     
          digitalWrite(orange1,LOW);   
          digitalWrite(orange2,LOW);
          digitalWrite(blue1,LOW);   
          digitalWrite(blue2,LOW);     
        }

void all(byte flag, byte numOfValues)
{
          digitalWrite(green1,LOW);   
          digitalWrite(green2,HIGH);
          digitalWrite(brown1,LOW);   
          digitalWrite(brown2,HIGH);     
          digitalWrite(orange1,LOW);   
          digitalWrite(orange2,HIGH);
          digitalWrite(blue1,LOW);   
          digitalWrite(blue2,HIGH);  
}

void green(byte flag, byte numOfValues)
        {        
          digitalWrite(green1,LOW);
          digitalWrite(green2,HIGH);
   
        }
void brown(byte flag, byte numOfValues)
        {        
          digitalWrite(brown1,LOW);
          digitalWrite(brown2,HIGH);
   
        }
void orange(byte flag, byte numOfValues)
        {        
          digitalWrite(orange1,LOW);
          digitalWrite(orange2,HIGH);
   
        }
void blue(byte flag, byte numOfValues)
        {        
          digitalWrite(blue1,LOW);
          digitalWrite(blue2,HIGH);
   
        }
void playall(byte flag, byte numOfValues)
{
    while(i<count)
  {
     green('o','o');delay(per);ting('o','o');delay(wait);
     brown('o','o');delay(per);ting('o','o');delay(wait);
     orange('o','o');delay(per); ting('o','o');delay(wait);    
     blue('o','o');delay(per);ting('o','o');delay(wait);
     all('o','o');delay(per);ting('o','o');delay(wait);
     i++;     
  }
}
