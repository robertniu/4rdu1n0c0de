#include <Wire.h> 
#include <LiquidCrystal_I2C.h>   
LiquidCrystal_I2C lcd(0x27,16,2); 
int brown1 = 6;
int brown2 = 7;
int green1 = 8;  
int green2 = 9;
int pos=0;
int dis=0;
long timer=60000;
int rd=3000;

void setup()
{
  lcd.init();   // initialize the lcd 
  lcd.backlight();
    pinMode(green1, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(brown1, OUTPUT);
    pinMode(brown2, OUTPUT);
  initlcd();
}
void loop()
{    
something();
}

void initlcd()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("pos");
  lcd.setCursor(5,0);
  lcd.print("d");
  lcd.setCursor(5,1);
  lcd.print(dis);
  lcd.setCursor(7,0);
  lcd.print("tim");
  lcd.setCursor(7,1);
  lcd.print(timer/1000);
  lcd.setCursor(12,0);
  lcd.print("rd");
  lcd.setCursor(12,1);
  lcd.print(rd); 
}

void something()
{
  delay(2000);
    for(int i=1; i<= rd; i++)  
  {    
    lcd.setCursor(0,1);
    lcd.print(i);    
   all();
   delay(200);
   ting();
   delay(timer);
   
  }
  
}

void all()
{
          digitalWrite(green1,LOW);   
          digitalWrite(green2,HIGH);
          digitalWrite(brown1,LOW);   
          digitalWrite(brown2,HIGH);     
 
}
void ting()
        {
          digitalWrite(green1,LOW);   
          digitalWrite(green2,LOW);
          digitalWrite(brown1,LOW);   
          digitalWrite(brown2,LOW);         
        }
        
