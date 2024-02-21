#ifndef HelpperMotorStepping
#define HelpperMotorStepping
#include "HelpLibary.h"


void forcerse(int stepNum){
 digitalWrite(enaPin, 0);
  digitalWrite(dirPin , 0);

for (int i = 0; i < stepNum; i++)
{
  Serial.println(i);
 digitalWrite(pulPin , 1);
 delayMicroseconds(1000);
 digitalWrite(pulPin , 0);
 delayMicroseconds(1000);
 
}



}

void reverse(int stepNum){
digitalWrite(dirPin , 0);
for (int i = 0; i < stepNum; i++)
{
  Serial.println(i);
 digitalWrite(pulPin , 1);
 delayMicroseconds(1000);
 digitalWrite(pulPin , 0);
 delayMicroseconds(1000);
 
}
delay(1000);

}

#endif 