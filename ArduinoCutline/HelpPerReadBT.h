#ifndef HelpBT
#define HelpBt
#include "HelpLibary.h"

String ReadSerial();
void Buttomtest();
int BtSumNum(int RawNum ,int MaxValue);


String ReadSerial()
{
String str = Serial.readString();

return str;
}


void Buttomtest(){
 int InputBt = ReadSerial().toInt();   
 
    switch (InputBt)
    {
    case 1:
        ButtonUP = true;
        break;
    case 2:
        ButtonDow = true;
        break;
    case 3 :
        ButtonOK =  true;
        break;
    case 4:
        ButtonCancls = true;
        break;
    case 13:
        ButtonUP = true;
        ButtonOK = true;
        break;
    case 23:    
        ButtonDow =true;
        ButtonOK =true;
        break;
    default:
        ButtonDow = false;
        ButtonUP = false;
        ButtonOK = false;
        ButtonCancls = false;
        break;
    }
}
int BtSumNum(int RawNum , int MaxValue){

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

return(RawNum);
}
#endif
