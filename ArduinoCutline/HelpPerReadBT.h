#ifndef HelpBT
#define HelpBt
#include "HelpLibary.h"

String ReadSerial();
void Buttomtest();
int BtSumNum(int RawNum, int MaxValue);
void ReSetButton();
void SetupButton()
{
    pinMode(InButtonlift, INPUT_PULLUP);
    pinMode(InButtonright, INPUT_PULLUP);
    pinMode(InButtonOK, INPUT_PULLUP);
    pinMode(InButtonCancls, INPUT_PULLUP);
}

void ReadButtonInput()
{
//if (millis() - timebBT > settimeBT){
    ButtonDow = !digitalRead(InButtonlift);
    ButtonUP = !digitalRead(InButtonright);
    ButtonOK = !digitalRead(InButtonOK);
    ButtonCancls = !digitalRead(InButtonCancls);
//   timebBT =millis();
//}
    // if (digitalRead(InButtonlift) == false)
    // {
    //     ButtonDow = true;

    // }
    // else if (digitalRead(InButtonlift) == true)
    // {
    //     ButtonDow = false;
    // }
    // if (digitalRead(InButtonright) == false)
    // {ButtonUP = true;

    // }
    // else if (digitalRead(InButtonright) == true){

    //     ButtonUP = false;
    // }
    //  if (digitalRead(InButtonOK) == false)
    // {
    //     ButtonOK = true;
    // }
    // else if (digitalRead(InButtonOK) == true){
    //     ButtonOK = false;
    // }
    //    if (digitalRead(InButtonCancls) == false)
    // {
    //     ButtonCancls = true;
    // }
    // else if (digitalRead(InButtonCancls) == true){
    //     ButtonCancls = false;
    // }
   // digitalWrite(10, ButtonUP);
    //digitalWrite(11, ButtonDow);
    //digitalWrite(12, ButtonOK);
    //digitalWrite(13, ButtonCancls);

    Serial.println("-----------------InPut---------------------------");
    Serial.println("InButtonlift" + String(digitalRead(InButtonlift)));
    Serial.println("InButtonright" + String(digitalRead(InButtonright)));
    Serial.println("InButtonOK" + String(digitalRead(InButtonOK)));
    Serial.println("InButtonCancls" + String(digitalRead(InButtonCancls)));
    Serial.println("-----------------output---------------------------");

    Serial.println("ButtonUP : " + String(ButtonUP));
    Serial.println("ButtonDow : " + String(ButtonDow));
    Serial.println("ButtonOK  : " + String(ButtonOK));
    Serial.println("ButtonCancls : " + String(ButtonCancls));

    Serial.println("-----------------ModeID---------------------------");
    Serial.println("ModeID : " + String(ModeID));

    return;
}
String ReadSerial()
{
    String str = Serial.readString();

    return str;
}

void ReSetButton()
{

    ButtonUP = false;
    ButtonDow = false;
    ButtonOK = false;
    ButtonCancls = false;
    //delay(200);
}

void Buttomtest()
{
    int InputBt = ReadSerial().toInt();

    switch (InputBt)
    {
    case 1:
        ButtonUP = true;
        break;
    case 2:
        ButtonDow = true;
        break;
    case 3:
        ButtonOK = true;
        break;
    case 4:
        ButtonCancls = true;
        break;
    case 13:
        ButtonUP = true;
        ButtonOK = true;
        break;
    case 23:
        ButtonDow = true;
        ButtonOK = true;
        break;
    default:
        ButtonDow = false;
        ButtonUP = false;
        ButtonOK = false;
        ButtonCancls = false;
        break;
    }
}

int BtSumNum(int RawNum, int MaxValue) // value olo RawNum of value is at update and    MaxValue is Value remit Value at ajust
{

    if (ButtonUP == true && RawNum < MaxValue)
    {
        /* code */
        RawNum++;
    }
    else if (ButtonDow == true && RawNum > 0)
    {
        /* code */
        RawNum--;
    }

    return (RawNum);
}
#endif
