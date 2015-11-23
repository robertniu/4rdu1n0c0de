int brown1 = 2;
int brown2 = 3;
int green1 = 4;  
int green2 = 5;
int orange1 = 6;  
int orange2 = 7;
int blue1 = 8;
int blue2 = 9;

int per=1000;
int wait=1000; //1000=1s
int count=3; 
int i=0;

void setup() 
{ 
    Serial.begin(9600);                     
    pinMode(green1, OUTPUT);
    pinMode(green2, OUTPUT);
    pinMode(brown1, OUTPUT);
    pinMode(brown2, OUTPUT);
    pinMode(orange1, OUTPUT);
    pinMode(orange2, OUTPUT);
    pinMode(blue1, OUTPUT);
    pinMode(blue2, OUTPUT);
} 
void loop() 
{ 
  delay(2000);
  while(i<count)
  {
     green();delay(per);ting();delay(wait);
     brown();delay(per);ting();delay(wait);
     orange();delay(per); ting();delay(wait);    
     blue();delay(per);ting();delay(wait);
     all();delay(per);ting();delay(wait);
     i++;     
  }
}
void ting(void)
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
void all(void)
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
void green(void)
        {        
          digitalWrite(green1,LOW);
          digitalWrite(green2,HIGH);
   
        }
void brown(void)
        {        
          digitalWrite(brown1,LOW);
          digitalWrite(brown2,HIGH);
   
        }
void orange(void)
        {        
          digitalWrite(orange1,LOW);
          digitalWrite(orange2,HIGH);
   
        }
void blue(void)
        {        
          digitalWrite(blue1,LOW);
          digitalWrite(blue2,HIGH);
   
        }

