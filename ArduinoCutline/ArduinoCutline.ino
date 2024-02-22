#include "HelpLibary.h" //เรียกไฟล์ ชื่อ HlepLibary.h
#include <AccelStepper.h>
#include <Servo.h>
String DataRaw;
#define dirPin 2
#define stepPin 3
#define motorInterfaceType 1
Servo myservo; // ประกาศตัวแปรแทน Servo
// Create a new instance of the AccelStepper class:
AccelStepper stepper = AccelStepper(motorInterfaceType, stepPin, dirPin);

void setup()
{
  stepper.setMaxSpeed(5000);
  stepper.setAcceleration(500);
  Serial.begin(115200);
  SetupButton();
  SetupLCD();

  myservo.attach(9); // กำหนดขา 9 ควบคุม Servo
  myservo.write(76);
  // put your setup code here, to run once:

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);

  digitalWrite(enaPin, HIGH);
  digitalWrite(dirPin, LOW);
  Serial.println("updete V 01.50");
  LCD_ShowStartRun(ModeMainName[NumMode]);
}

void loop()
{
  // test();
   ReadButtonInput();

  if (ModeID == "Standby")
 {
    CallSelectMainModeID();
  }
   else if (ModeID == "Setting")
  {
     CallSettingMode();
   }
  else if (ModeID == "Start")
  {
     RunningProcess();
   }
  else
  {
   ModeID = "Standby";
}
  // //  testsum();
  //Servotest();
  //SteppingMoTor();

}

void RunningProcess()
{
  stackCount = 0;
  PWMCut = CalDataSetToPwm(SetCut.toFloat());
  while (stackCount < Count.toInt())
  {
    if (stackCount != Count.toInt())
    {
      myservo.write(0);
      delay(500);
    }
    RunMotorStepping(PWMCut);
  }
}
void RunMotorStepping(long TempPWM)
{
  while (stepper.currentPosition() < TempPWM)
  {
    stepper.move(TempPWM);
    stepper.run();

    Serial.println(stepper.currentPosition());
    PWMStapping = CalPWMToM(stepper.currentPosition());
    LCD_ShowRun(String(PWMStapping), "Running");
    if (stepper.currentPosition() > TempPWM)
    {
      stepper.setCurrentPosition(0);
      stepper.stop();
      myservo.write(76);
      delay(1000);
      stackCount += 1;
      break;
    }
  }
}

void Servotest()
{

  myservo.write(0);   // สั่งให้ Servo หมุนไปองศาที่ 0
  delay(1000);        // หน่วงเวลา 1000ms
  myservo.write(90);  // สั่งให้ Servo หมุนไปองศาที่ 90
  delay(1000);        // หน่วงเวลา 1000ms
  myservo.write(180); // สั่งให้ Servo หมุนไปองศาที่ 180
  delay(1000);        // หน่วงเวลา 1000ms
}

void SteppingMoTor()
{

  stepper.move(6400);
  stepper.run();
  Serial.println(stepper.currentPosition());
  Serial.print("M");
  Serial.println(CalPWMToM(stepper.currentPosition()), 3);
  Serial.print("Call : ");
  Serial.println(CalDataSetToPwm(0.245));
  Serial.print("Call : ");
  int i = round(CalDataSetToPwm(0.245));
  Serial.println(i);
  while (stepper.currentPosition() > 6400)
  {

    stepper.setCurrentPosition(0);
    stepper.stop();
    delay(1000);
    break;
  }


stepper.move(6400);
stepper.run();
Serial.println(stepper.currentPosition());
//  Serial.print("M");
//  Serial.println(CalPWMToM(stepper.currentPosition()),3);
//  Serial.print("Call : ");
//  Serial.println(CalDataSetToPwm(0.245));
//  Serial.print("Call : ");
// int i= round(CalDataSetToPwm(0.245));
//  Serial.println(i);
while (stepper.currentPosition() > 6400)
{

  stepper.setCurrentPosition(0);
  stepper.stop();
  delay(1000);
  break;
}
}

// void testsum()
// {

//   /* code */
//   String Olocut = SetCut;
//   int SumData = SetCut.toInt(); // Extracting the integer part of NewSetcut
//   int location = 0;
//   Serial.println("SetCut " + String(SetCut[0]));

//   while (true)
//   {

//     // Serial.println("NewSetcut :" + SumData);
//     //test();
// ReadButtonInput();
//     Serial.println("SumData :" + String(SumData));
//     Serial.println("location " + String(location));
//     if (ButtonUP == true)
//     {
//       if (SumData <= 9000)
//       {
//         if (location == 0)
//         {
//           SumData += 1000;
//         }
//         else if (location == 1)
//         {
//           SumData += 100;
//         }
//         else if (location == 2)
//         {
//           SumData += 10;
//         }
//         else if (location == 3)
//         {
//           SumData += 1;
//         }
//       }
//     }
//     else if (ButtonDow == true)
//     {
//       if (location == 0 && SumData >= 1000)
//       {
//         SumData -= 1000;
//       }
//       else if (location == 1 && SumData >= 100)
//       {
//         SumData -= 100;
//       }
//       else if (location == 2 && SumData >= 10)
//       {
//         SumData -= 10;
//       }
//       else if (location == 3 && SumData >= 1)
//       {
//         SumData -= 1;
//       }
//     }
//     else if (ButtonOK == true)
//     {
//       location += 1;
//       if (location == 4)
//       {
//         break;
//       }
//     }
//   }
// }