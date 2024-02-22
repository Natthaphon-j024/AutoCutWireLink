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
   int NumID[] = {10, 20, 100};
   int OloNumID = 0;

   if (ModeID == "Setting")
   {
      LCD_Setting(ModeSetupName[NumSelect]);
      while (ModeID == "Setting")
      {
         Serial.println("ModeIDSet:" + String(ModeIDSet));
         test(); // Print Paramiter Button input1
         NumSelect = BtSumNum(NumSelect, 3);

         Serial.println("NumSelect:" + String(NumSelect));
         // select Setup praramiter
         if (ModeIDSet == 0)
         {
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
            CallSetupData(String(SetCut), "SetupSC");
            ModeIDSet = 0;
         }

         else if (ModeIDSet == 20)
         {   
            CallSetupCount(Count, "SetupCC");
            ModeIDSet = 0;
         }
           else if (ModeIDSet == 100)
         {  
            ModeID = "Standby";
         }
      }
   }
}

void CallSetupData(String Data, String TempName)
{
   /* setup  Value cut   */
   String Olocut = Data;
   int SumData = Data.toInt(); // Extracting the integer part of NewSetcut
   int location = 0;
   int OloSumData;
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
      }
      if (OloSumData != SumData)
      {
         SetCut = SumData;
         LCD_Setting(TempName);

         // CallUpdata(String(SumData), TempName);
      }
      if (location == 4)
      {
         break;
      }
   }
}

void CallSetupCount(String Data, String TempName)
{
   /* setup  Value cut   */
   String Olocut = Data;
   int SumDataCount = Data.toInt(); // Extracting the integer part of NewSetcut
   int OloSumDataCount;
   while (true)
   {
      // Serial.println("NewSetcut :" + SumData);
      test();
      Serial.println("SumData :" + String(SumDataCount));
      if (ButtonUP == true)
      {
         if (SumDataCount <= 99)
         {

            SumDataCount += 1;
         }
      }
      else if (ButtonDow == true)
      {
         if (SumDataCount >= 100)
         {
            SumDataCount -= 1;
         }
         else if (ButtonOK == true)
         {
            break;
         }
         if (OloSumDataCount != SumDataCount)
         {
            Count = SumDataCount;
            LCD_Setting(TempName);
            OloSumDataCount = SumDataCount;
         }
      }
   }
}

#endif