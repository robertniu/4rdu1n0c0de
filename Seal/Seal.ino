#include <MeetAndroid.h>
// declare MeetAndroid so that you can call functions with it
MeetAndroid meetAndroid;
int EN2 = 2;   
int EN3 = 3;
int EN4 = 4;
int EN5 = 5;

void setup()  
{
  Serial.begin(9600);
  
  // register callback functions, which will be called when an associated event occurs.
  meetAndroid.registerFunction(qian, 'o');
  meetAndroid.registerFunction(hou, 'p');  
  meetAndroid.registerFunction(ting, 'q'); 
  meetAndroid.registerFunction(zuo, 'r');
  meetAndroid.registerFunction(you, 's');  
  // set all color leds as output pins
  pinMode(EN2, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);
  pinMode(EN5, OUTPUT);

  
  digitalWrite(EN2,LOW);   
  digitalWrite(EN3,LOW);
  digitalWrite(EN4,LOW);   
  digitalWrite(EN5,LOW);


}

void loop()
{
  meetAndroid.receive(); // you need to keep this in your loop() to receive events
}

/*
 * Whenever the multicolor lamp app changes the red value
 * this function will be called
 */
void qian(byte flag, byte numOfValues)
{
          digitalWrite(EN2,LOW);
          digitalWrite(EN3,HIGH);
          digitalWrite(EN4,LOW);
          digitalWrite(EN5,HIGH);

}

/*
 * Whenever the multicolor lamp app changes the green value
 * this function will be called
 */
void hou(byte flag, byte numOfValues)
{
          digitalWrite(EN2,HIGH);
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,HIGH);
          digitalWrite(EN5,LOW);
  //analogWrite(greenLed, meetAndroid.getInt());
}

/*
 * Whenever the multicolor lamp app changes the blue value
 * this function will be called
 */
void ting(byte flag, byte numOfValues)
{
  digitalWrite(EN2,LOW);   
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);   
          digitalWrite(EN5,LOW);

  //analogWrite(blueLed, meetAndroid.getInt());
}

void you(byte flag, byte numOfValues)
{
          digitalWrite(EN2,HIGH);
          digitalWrite(EN3,LOW);
          digitalWrite(EN4,LOW);
          digitalWrite(EN5,HIGH);
  //analogWrite(greenLed, meetAndroid.getInt());
}

void zuo(byte flag, byte numOfValues)
{
          digitalWrite(EN2,LOW);
          digitalWrite(EN3,HIGH);
          digitalWrite(EN4,HIGH);
          digitalWrite(EN5,LOW);

  //analogWrite(greenLed, meetAndroid.getInt());
}

