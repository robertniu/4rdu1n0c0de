
int EN2 = 2;  
int EN3 = 3;
int EN4 = 4;
int EN5 = 5;
int per=200;
int wait=5000; //1000=1s
int count=20; 
int i=0;

void setup() 
{ 
    Serial.begin(9600);                     
    pinMode(EN2, OUTPUT);
    pinMode(EN3, OUTPUT);
    pinMode(EN4, OUTPUT);
    pinMode(EN5, OUTPUT);
} 
void loop() 
{ 
  delay(2000);
  while(i<count)
  {
     qian();
     delay(per);
     ting();
     delay(wait);
     i++;
     
  }
}
void ting(void)
        {
          digitalWrite(EN2,LOW);   
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);   
          digitalWrite(EN5,LOW);       
        }
        
void qian(void)
        {        
          digitalWrite(EN2,LOW);
          digitalWrite(EN3,HIGH);
          digitalWrite(EN4,LOW);
          digitalWrite(EN5,HIGH);     
        }
void hou(void)
        {        
          digitalWrite(EN2,HIGH);
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,HIGH);
          digitalWrite(EN5,LOW);            
        }
void zuo(void)
        {        
          digitalWrite(EN2,HIGH);
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);
          digitalWrite(EN5,HIGH);
          
        }
void you(void)
        {        
          digitalWrite(EN2,LOW);
          digitalWrite(EN3,HIGH);
          digitalWrite(EN4,HIGH);
          digitalWrite(EN5,LOW);     
        }  

