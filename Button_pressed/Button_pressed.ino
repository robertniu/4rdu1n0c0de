#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
int Switch1 = 4;
int button;
int cod=0;
int tobeornottobe=0;

void setup()
{
  lcd.init();   // initialize the lcd 
  lcd.backlight();
  pinMode(Switch1, INPUT);
  initlcd();
  Serial.begin(9600);
  Serial.println("\nButton Scanner");
 // Serial.println(LOW); //LOW=UNPRESSED=0
}
void loop()
{
  if(tobeornottobe==0)
 {
 getinput();
 //something();
 tobeornottobe++;
 }
}

void getinput()
{
 while(1)
{
  button=pulseIn(Switch1,HIGH,20000000); //20seconds
 Serial.println(button);
 
 if(button==0)
 {
 Serial.println("UNPERSSED");
 break;
 }
 if(button!=0)
 {
  Serial.println("PERSSED");
  pressed();
  
 }
  
} 
}

void pressed()
{
  if (cod==0){
lcd.setCursor(0,1);
  lcd.print("345"); cod++; 
  }
  else if(cod==1){
    lcd.setCursor(0,1);
  lcd.print("678"); cod++;
  }
  else if(cod!=0){
    lcd.setCursor(0,1);
    lcd.print("100");cod=0;
  }
}

void initlcd()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("pos");
  lcd.setCursor(0,1);
  lcd.print("100");
}

