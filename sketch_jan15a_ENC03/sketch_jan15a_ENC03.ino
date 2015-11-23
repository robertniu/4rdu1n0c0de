#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#define AnalogPinX 1        
#define AnalogPinY 2      
#define AnalogPinZ 3      
LiquidCrystal_I2C lcd(0x27,16,2); 
int ang_speed_x=0,ang_speed_y=0,ang_speed_z=0;
int g_offx=1337,g_offy=1357,g_offz=1337;
void setup()
{
lcd.init();   // initialize the lcd 
lcd.backlight();

}
void loop()
{
lcd.clear();
lcd.setCursor(0,0);
lcd.print("x=");
lcd.setCursor(5,0);
lcd.print("y=");
lcd.setCursor(10,0);
lcd.print("z=");
delay(50); 
 ang_speed_x=((analogRead(AnalogPinX)*5000.00/1024)-g_offx)/0.67;
 //ang_speed_x=analogRead(AnalogPinX)*5000.00/1024;
 lcd.setCursor(0,1);
 lcd.print(ang_speed_x);

 
 ang_speed_y=((analogRead(AnalogPinY)*5000.00/1024)-g_offy)/0.67;
 //ang_speed_y=analogRead(AnalogPinY)*5000.00/1024;
 lcd.setCursor(5,1);
 lcd.print(ang_speed_y);
 
 //ang_speed_z=((analogRead(AnalogPinZ)*5000.00/1024)-g_offz)/0.67;
 ang_speed_z=analogRead(AnalogPinZ)*5000.00/1024;
 lcd.setCursor(10,1);
 lcd.print(ang_speed_z);


 delay(1000);
} 

