#ifndef HelpCall // ทำสิ่งที่คุณต้องการเมื่อ HelpLibary มีการใช้งาน
#define HelpCall
#include "HelpLibary.h"
void CallSelectMainModeID();
void CallSetupData(String Data ,String TempName);
void test()
{
   Buttomtest();

   Serial.println("up:" + String(ButtonUP));
   Serial.println("dow:" + String(ButtonDow));
   Serial.println("ok:" + String(ButtonOK));
   Serial.println("clase:" + String(ButtonCancls));
   Serial.println("ModeID: " + ModeID);
}

void CallSelectMainModeID()
{
   int OloNumMode = 0;
   while (ModeID == "Standby")
   {
      test();
      if (ButtonUP == true && NumMode <= 2)
      {
         NumMode++;
      }
      else if (ButtonDow == true && NumMode >= 1)
      {
         NumMode--;
      }
      else if ((NumMode > 2 || NumMode < 0) || (ButtonDow == true || ButtonUP == true))
      {
         NumMode = 0;
      }
      if (OloNumMode != NumMode)
      {
         if (ModeMainName[NumMode] == "Setting")
         {
            LCD_Setting(ModeMainName[NumMode]);
         }
         else if (ModeMainName[NumMode] == "Standby" || ModeMainName[NumMode] == "Start")
         {
            LCD_ShowStartRun(ModeMainName[NumMode]);
         }
      }
      if (ModeID == "Standby" && ButtonOK == true)
      {

         Serial.println(ModeMainName[NumMode]);
         ModeID = ModeMainName[NumMode];
         break;
      }

      delayMicroseconds(1000);
   }
}

void CallSettingMode()
{
   int NumSelect = 0;
   String OloSetCut = SetCut;
   String OloCount = Count;
   int ModeIDSet = 0;
   int NumID[] = {10, 20, 30, 100};
   int OloNumID = 0;


   if (ModeID == "Setting")
   {LCD_Setting(ModeSetupName[NumSelect]);
      while (ModeID == "Setting")
      {
         Serial.println("ModeIDSet:" + String(ModeIDSet));
         test(); //Print Paramiter Button input1
         NumSelect = BtSumNum(NumSelect , 3);
         
   Serial.println("NumSelect:" + String(NumSelect));
         // select Setup praramiter 
         if (ModeIDSet == 0)
         {
            if (NumSelect != OloNumID)
            {
               LCD_Setting(ModeSetupName[NumSelect]);
               OloNumID=NumSelect;
            }

            if (ButtonOK == true)
            {
                Serial.println("ButtonOK :" + String(ModeSetupName[NumSelect]));
               LCD_Setting(ModeSetupName[NumSelect]);
               ModeIDSet = NumID[NumSelect];
            }
            else if (ButtonCancls == true)
            {
               LCD_Setting("Cancls Setup");
               while (true)
               {
                  if (ButtonOK == true)
                  {
                     SetCut = OloSetCut;
                    
                     Count = OloCount;
                     ModeID = "Standby";
                     break;
                  }
                  else if (ButtonCancls == true)
                  {
                     break;
                  }
               }

            }
         }
         //-----------End Select setup-------------

         else if (ModeIDSet == 10)
         {  
            CallSetupData(String(SetCut),"SetupSC");
            ModeIDSet = 0;
         }
         
      }
   }
}




   void CallSetupData(String Data ,String TempName)
{
    int lenData = Data.length();
    int LocaltionData = 0;
    int SumData = 0;
    int OloSumData;
    while (true)
    {     
       
        test;
        SumData = String(Data[LocaltionData]).toInt();
        Serial.println("SumData:" + String(SumData));
        /* */
        if (ButtonUP == true)
        {
            SumData++;
        }
        else if (ButtonDow == true)
        {
            SumData--;
        }
        if (ButtonOK == true)
        {
            LocaltionData++;
        }
        else if (ButtonCancls == true)
        {
            LocaltionData--;
        }
        if (String(Data[LocaltionData]).toInt() > 0  || String(Data[LocaltionData]).toInt() < 9  ){
             String(Data[LocaltionData]) = String(SumData);
        }
        if (SumData != OloSumData){
       LCD_Setting(TempName);
        OloSumData = SumData;
        }
        
    }
   
    // Serial.println("Value max : " + String(lenData));
    //  for (int i = 0; i < lenData; i++)
    //  {
    //  Serial.println("Value i : "+ String(i));    /* code */

    // Serial.println(Data[i]);    /* code */
}
void CallUpdata(String TempData , String LocatiosUpde)
{
if (LocatiosUpde == "SetupSC"){
SetCut = TempData;
}
else if (LocatiosUpde=="SetupCC")
{
Count = TempData;
}
}

#endif