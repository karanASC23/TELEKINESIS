#include<IRremote.h>
const int RemotePin=8;
 
int in1=3;
int in2=5;
int in3=6;
int in4=9;
int EnA = 2;
int EnB = 10;


void setup() {
  Serial.begin(9600);
  IrReceiver.begin(RemotePin, ENABLE_LED_FEEDBACK);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(EnA, OUTPUT);
  pinMode(EnB, OUTPUT);
}

void loop() {
 
    if(IrReceiver.decode())
      {
         uint16_t command = IrReceiver.decodedIRData.command; // Get the IR command
       
        Serial.print("Received Command: 0x"); // Debugging: Print command value
        Serial.println(command, HEX);
       
        if (command==0x46)//Press UP Button
        {
          Forward();
        }
        else if (command==0x15)//Press Down Button
        {
          Backward();
        }
         else if (command==0x44)//Press Left Button
        {
          Left();
        }
        else if (command==0x43)//Press Right Button
        {
          Right();
        }
            else if (command==0x40)//Stop           
        {
          Stop();
        }
      IrReceiver.resume();
    }
}
   
 
void Backward()
  {
  analogWrite(EnA, 0);
  analogWrite(EnB, 0);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  }
 void Forward()
  {
  Serial.println("Moving Forward");
  analogWrite(EnA, 63);
  analogWrite(EnB, 63);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  }
 void Stop()
  {
  analogWrite(EnA, 63);
  analogWrite(EnB, 63);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  }
void Left()
    {
    analogWrite(EnA, 63);
    analogWrite(EnB, 63);
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    }
void Right()
    {
    analogWrite(EnA, 63);
    analogWrite(EnB, 63);
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    }
