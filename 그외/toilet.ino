#include <SoftwareSerial.h>
#include <Servo.h> 
 
int servoPin = 9;
Servo servo; 
int angle = 0; // servo position in degrees 
SoftwareSerial btSerial(2,3);

void setup()
{
  Serial.begin(9600);
  btSerial.begin(9600); 
  pinMode(7, OUTPUT);
  pinMode(5, INPUT);
  servo.attach(servoPin); 
}

bool first = true;
void loop()
{
    if(Serial.available())
    {
      delay(5);  
      while(Serial.available())
      {
        btSerial.write(Serial.read());
      }
    }
    if(btSerial.available())
    {
      delay(5);  
      while(btSerial.available())
      {
        byte data = btSerial.read();
        if(data == '$'){
          if(!first){
            btSerial.write("can't use\n");
          }
          else{
            btSerial.write("ads\n");
            delay(1000);
            digitalWrite(7, HIGH);
            for(angle = 10; angle < 170; angle++) 
            { 
              servo.write(angle); 
              delay(10); 
            } 
            btSerial.write("open\n");
          }
        }
        if(data == '%'){
          digitalWrite(7, LOW);
          for(angle = 170; angle > 10; angle--) 
          { 
            servo.write(angle); 
            delay(10); 
          } 
          btSerial.write("close\n");
        }
        Serial.write(data);
      }
    }
    if(digitalRead(5) && first){
      btSerial.write("using\n");
      first = false;
    }
    if(digitalRead(5) == false && first == false){
      btSerial.write("empty\n");
      first = true;
    }
}
