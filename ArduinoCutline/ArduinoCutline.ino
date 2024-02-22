#include "HelpLibary.h" //เรียกไฟล์ ชื่อ HlepLibary.h

String DataRaw;

void setup()
{

  Serial.begin(115200);

  SetupLCD();
  // put your setup code here, to run once:
  pinMode(pulPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enaPin, OUTPUT);

  digitalWrite(enaPin, HIGH);
  digitalWrite(dirPin, LOW);
  Serial.println("updete V 01.33");
  LCD_ShowStartRun(ModeMainName[NumMode]);
}

void loop()
{
  test();
    if (ModeID == "Standby")
     {
      CallSelectMainModeID();
  }
   else if (ModeID == "Setting")
   {
    CallSettingMode();
   }
//  testsum();
}

void testsum()
{

  /* code */
  String Olocut = SetCut;
  int SumData = SetCut.toInt(); // Extracting the integer part of NewSetcut
  int location = 0;
  Serial.println("SetCut " + String(SetCut[0]));

  while (true)
  {

    // Serial.println("NewSetcut :" + SumData);
    test();
    Serial.println("SumData :" + String(SumData));
    Serial.println("location " + String(location));
    if (ButtonUP == true)
    {
      if (SumData <= 9000)
      {
        if (location == 0)
        {
          SumData += 1000;
        }
        else if (location == 1)
        {
          SumData += 100;
        }
        else if (location == 2)
        {
          SumData += 10;
        }
        else if (location == 3)
        {
          SumData += 1;
        }
      }
    }
    else if (ButtonDow == true)
    {
      if (location == 0 && SumData >= 1000)
      {
        SumData -= 1000;
      }
      else if (location == 1 && SumData >= 100)
      {
        SumData -= 100;
      }
      else if (location == 2 && SumData >= 10)
      {
        SumData -= 10;
      }
      else if (location == 3 && SumData >= 1)
      {
        SumData -= 1;
      }
    }
    else if (ButtonOK == true)
    {
      location += 1;
      if (location == 4)
      {
        break;
      }
    }
  }
}