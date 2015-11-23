#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>       
int addr = 0;
LiquidCrystal_I2C lcd(0x27,16,2); 
int brown1 = 6;
int brown2 = 7;
int green1 = 8;  
int green2 = 9;
int pos=0;
int dis=0;
long timer1=60000;
long timer2=30000;
long timer3=15000;
long timer4=10000;
long timer5=5000;
long timer6=1000;
long timer=timer1;
int rd=3000;
int tobeornottobe=0;
//
int Switch1 = 4;
int button;
int cod=0;
//

void setup()
{
  lcd.init();   // initialize the lcd 
  lcd.backlight();
    pinMode(green1, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(brown1, OUTPUT);
    pinMode(brown2, OUTPUT);
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
  button=pulseIn(Switch1,HIGH,15000000);
 if(button==0){break;}
 if(button!=0) {  pressed();}
  }
  something();
}
void pressed()
{
  if (cod==0){
             timer=timer2;
             cod++;
             initlcd2(); 
  }
  else if(cod==1){
                  timer=timer3;
                  cod++;
                  initlcd2();
  }
  else if(cod==2){
                  timer=timer4;
                  cod++;
                  initlcd2();
  }
  else if(cod==3){
                  timer=timer5;
                  cod++;
                  initlcd2();
  }
   else if(cod==4){
                  timer=timer6;
                  cod++;
                  initlcd2();
  }
  else if (cod!=0){           
                   timer=timer1;
                   cod=0;
                   initlcd2();
  }
}

void initlcd2()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("INPUT TIME VALUE:");
  lcd.setCursor(0,1);
  lcd.print(timer/1000);
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
  
  initlcd();
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
        
void write(int value)
{
EEPROM.write(addr,value);
addr=addr+1;
if(addr==512)
{
  addr=0;
  delay(100);
}
}


void read(int addr)
{
  int value=0;
  for(int i=0;i<10;i++)
  {
    value= EEPROM.read(addr++);
  }
}
