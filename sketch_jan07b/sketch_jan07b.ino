#include <Servo.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Servo myservo;  // create servo object to control a servo   
int tobeornottobe=0;
int pos = 0;    // variable to store the servo position
int midPulseWidth=1450; //90
int minPulseWidth=590; //0
int maxPulseWidth=2200; //180   134.1667=15degree
int posa = 590; //begin from
int posb = 2200; //end of
int dis = 1; //each time 8.94=1degree 
int timer = 300; //wait for 1000=1s 
int rd=(posb-posa)/dis;
// (posb-posa)*timer/dis=totaltime
//set timer=26832 and dis=1 will make it run like a heq5pro , turn 15degree per 1 hour
//set time=100 and dis=1 will make it run 161sec and 180degree ,if gopro set 0.5sec ,it will make 322pics  
 
void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  lcd.init();   // initialize the lcd 
  lcd.backlight();
}
 
 
void loop()
{
 if(tobeornottobe==0)
 {
 something();
 tobeornottobe++;
 }
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
  lcd.print(timer);
  lcd.setCursor(12,0);
  lcd.print("rd");
  lcd.setCursor(12,1);
  lcd.print(rd); 
}

void something()
{
  initlcd();
  delay(2000);
    for(pos = midPulseWidth; pos >=posa; pos -= 5)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
  myservo.writeMicroseconds(posa);
  delay(2000);
  for(pos = posa; pos <=posb; pos += dis)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(timer);                       // waits 15ms for the servo to reach the position
    lcd.setCursor(0,1);
    lcd.print(pos);
  }
   delay(2000);
    for(pos = posb; pos >= posa; pos -= dis)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(timer);                       // waits 15ms for the servo to reach the position
    lcd.setCursor(0,1);
    lcd.print(pos);
  }
  
  
  //myservo.writeMicroseconds(midPulseWidth);
  delay(2000);
  for(pos = posa; pos <=midPulseWidth; pos += 5)  // goes from 0 degrees to 180 degrees
  {                                  // in steps of 1 degree
    myservo.writeMicroseconds(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  delay(2000);
  myservo.detach();

}


