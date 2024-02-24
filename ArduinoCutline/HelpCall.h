#ifndef HelpCall // ทำสิ่งที่คุณต้องการเมื่อ HelpLibary มีการใช้งาน
#define HelpCall
#include "HelpLibary.h"
void CallSelectMainModeID();
void CallSetupData(String Data, String TempName);
void CallSetupCount(String Data, String TempName);
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
   ReadButtonInput();
   int OloNumMode = 0;
   NumMode = 0;

   // ReSetButton();
   LCD_ShowStartRun(ModeMainName[NumMode]);
   if (ModeID == "Standby")
   {
      while (true)
      {
         Serial.println("ModeID: " + ModeID);
         // test();
         ReadButtonInput();
         if (ButtonUP == true && NumMode < 2)
         {
            NumMode++;
            Serial.println("NumMode++:" + String(NumMode));
         }
         else if (ButtonDow == true && NumMode >= 1)
         {
            NumMode--;
            Serial.println("NumMode--:" + String(NumMode));
         }
         // else if ((NumMode > 2 || NumMode < 0) || (ButtonDow == true || ButtonUP == true))
         // {
         //    NumMode = 0;
         // }
         Serial.println("OloNumMode:" + String(OloNumMode));
         Serial.println("NumMode:" + String(NumMode));
         if (OloNumMode != NumMode)
         {
            Serial.println("Update LCD CallSelectMainModeID");
            if (ModeMainName[NumMode] == "Setting")
            {
               LCD_Setting(ModeMainName[NumMode]);
            }
            else if (ModeMainName[NumMode] == "Standby" || ModeMainName[NumMode] == "Start")
            {
               LCD_ShowStartRun(ModeMainName[NumMode]);
            }
            OloNumMode = NumMode;
         }
         if (ModeID == "Standby" && ButtonOK == true)
         {
            Serial.println("ok Update LCD CallSelectMainModeID");
            Serial.println(ModeMainName[NumMode]);
            ModeID = ModeMainName[NumMode];
            break;
         }
         ReSetButton();
         delayMicroseconds(10000);
      }
   }
}

void CallSettingMode()
{
   int NumSelect = 0;
   String OloSetCut = SetCut;
   String OloCount = Count;
   ModeIDSet = 0;
   int NumID[] = {10, 20, 100};
   int OloNumID = 0;
   unsigned long timeCallSettingMode = 0;

   timeCallSettingMode = millis();
   if (ModeID == "Setting")
   {
      Serial.println("=------------------Setting:------------------------------");
      LCD_Setting(ModeSetupName[NumSelect]);
      if (ModeIDSet == 0)
            {
      while (true)
      {
    
         if (millis() - timeCallSettingMode > 200)
         {
            // ReSetButton();
            Serial.println("ModeIDSet:" + String(ModeIDSet));
            // test(); // Print Paramiter Button input1
            ReadButtonInput();
            NumSelect = BtSumNum(NumSelect, 2);

            Serial.println("NumSelect:" + String(NumSelect));
            // select Setup praramiter
        
               if (NumSelect != OloNumID)
               {
                  LCD_Setting(ModeSetupName[NumSelect]);
                  OloNumID = NumSelect;
               }

               if (ButtonOK == true)
               {
                  Serial.println("ButtonOK :" + String(ModeSetupName[NumSelect]));
                  LCD_Setting(ModeSetupName[NumSelect]);
                  ModeIDSet = NumID[NumSelect];
                  break;
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
               timeCallSettingMode = millis() ;
            }
             }
            //-----------End Select setup-------------

             
             
         }

     if (ModeIDSet == 10)
            {
               CallSetupData(String(SetCut), "SetupSC");
               ModeIDSet = 0;
            }

            else if (ModeIDSet == 20)
            {
               CallSetupCount(Count, "SetupCC");
               ModeIDSet = 0;
            }
            else if (ModeIDSet == 100)
            {Serial.println("ModeIDSet : 1000 " );
               ModeID = "Standby";
               NumSelect = 0;
            }
   }
}

void CallSetupData(String Data, String TempName)
{
   /* setup  Value cut   */
   String Olocut = Data;
   int SumData = Data.toInt(); // Extracting the integer part of NewSetcut
   unsigned long timeCallSetupData = millis();
   int OloSumData;
   ReadButtonInput();
   while (true)
   {
      // Serial.println("NewSetcut :" + SumData);
      // test();
      if (millis() - timeCallSetupData >  200)
      {
         // ReSetButton();
         Serial.println("SumData :" + String(SumData));
         ReadButtonInput();
         if (ButtonUP == true)
         {
            if (SumData <= 9000)
            {

               SumData += 1;
            }
         }
         else if (ButtonDow == true)
         {
            if (SumData != 1)
            {

               SumData -= 1;
            }
         }
         if (ButtonOK == true)
         {
            SetCut = SumData;
            ModeIDSet= 0;
            break;
            CallSettingMode();
         }
         if (OloSumData != SumData)
         {
            SetCut = SumData;
            LCD_Setting(TempName);

            // CallUpdata(String(SumData), TempName);
         }
         timeCallSetupData = millis();
      }
   }
}

void CallSetupCount(String Data, String TempName)
{
   /* setup  Value cut   */
   String Olocut = Data;
   int SumDataCount = Data.toInt(); // Extracting the integer part of NewSetcut
   int OloSumDataCount;
   unsigned long timeCallSetupCount = millis();
   Serial.println("CallSetupCount");
   while (true)
   {
      if (millis() - timeCallSetupCount > 500)
      {
         ReSetButton();
         Serial.println("CallSetupCount while");
         // Serial.println("NewSetcut :" + SumData);
         // test();
         ReadButtonInput();
         Serial.println("SumData :" + String(SumDataCount));
         if (ButtonUP == true)
         {
            if (SumDataCount < 99)
            {

               SumDataCount += 1;
            }
         }
         else if (ButtonDow == true)
         {
            if (SumDataCount > 0)
            {
               SumDataCount -= 1;
            }
         }
         if (ButtonOK == true)
         {
            Serial.println("CallSetupCount break while ");
            ModeIDSet = 0;
           
            Count = SumDataCount;
             break;
         }
         if (OloSumDataCount != SumDataCount)
         {
            Count = SumDataCount;
            LCD_Setting(TempName);
            OloSumDataCount = SumDataCount;
         }
      timeCallSetupCount = millis();
      }
   }
}

#endif