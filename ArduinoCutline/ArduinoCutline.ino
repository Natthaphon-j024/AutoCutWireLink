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
  Serial.println("updete V 01.13");
  LCD_ShowStartRun(ModeMainName[NumMode]);
}

void loop()
{
  // test();
  if (ModeID == "Standby")
  {
    CallSelectMainModeID();
  }
  else if (ModeID == "Setting")
  {
    CallSettingMode();
  }
}
