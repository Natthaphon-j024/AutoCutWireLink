#ifndef HelpLCD
#define HelpLCD

#include "HelpLibary.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
// LiquidCrystal_I2C lcd(0x3F, 16, 2);

void LCDSelectMainMode(int temp);
void LCDSetupMode(int temp, int Location);
void TestLCD();
void SetupLCD();

void TestLCD()
{

  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);          // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print("1234567890");      // พิมพ์ข้อความ
  lcd.setCursor(2, 1);          // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("asdfghjkl;");      // พิมพ์ข้อความ "arduinoall.com"
  lcd.setCursor(0, 2);          // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print("ArduinoAll TEST"); // พิมพ์ข้อความ
  lcd.setCursor(2, 3);          // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("zxcvbnm,");        // พิมพ์ข้อความ "arduinoall.com"
}
void LCD_SetupMode(int temp, int Location)
{

  if (Location == 0)
  { String  t = ModeMainName[temp];
    lcd.clear();
    lcd.setCursor(t.length(), 0);                                  // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
    lcd.print(String(ModeSetupName[temp])); // พิมพ์ข้อความ
  }
  else if (Location == 1)
  {
    lcd.setCursor(2, 1);                        // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
    lcd.print("SetCut : " + String(34) + "m."); // พิมพ์ข้อความ "arduinoall.com"
  }
  else if (Location == 2)
  {
    lcd.setCursor(0, 2);                           // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
    lcd.print("CutSheath :" + String(23) + "mm."); // พิมพ์ข้อความ
  }
  else if (Location == 4)
  {
    lcd.setCursor(2, 3);                            // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
    lcd.print("CountCable : " + String(34) + "w."); // พิมพ์ข้อความ "arduinoall.com"
  }
  delayMicroseconds(1000);
}
void LCD_Setting(String temp)
{

  lcd.clear();
  lcd.setCursor((21-temp.length())/2, 0);                           // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print(String(temp));           // พิมพ์ข้อความ
  lcd.setCursor(5, 1);                           // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Cut:" + String(SetCut.toFloat()/100,2) + " m.");    // พิมพ์ข้อความ "arduinoall.com"
  lcd.setCursor(3, 2);                           // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Count:" + String(Count) + " w.");      // พิมพ์ข้อความ "arduinoall.com"

  delayMicroseconds(1000);
}
void LCD_ShowStartRun(String temp)
{
  lcd.clear();
  lcd.setCursor((21-temp.length())/2, 0);                                         // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print(String(temp));                         // พิมพ์ข้อความ
  lcd.setCursor(3, 1);                                         // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Length:" + String(000.000) + " m.");                   // พิมพ์ข้อความ "arduinoall.com"
  lcd.setCursor(6, 2);                                         // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print("Cut:" + String(SetCut.toFloat()/100,2) + " m.");                     // พิมพ์ข้อความ
  lcd.setCursor(4, 3);                                         // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Count:" + String(Count) + "|" + String(00) + " w."); // พิมพ์ข้อความ "arduinoall.com"
  delayMicroseconds(1000);
}

void ClsLCD(int BanTunNum)
{
  Serial.println("Cls");
  for (int Cals = 19; Cals >= 0; Cals--)
  {
    lcd.setCursor(Cals, BanTunNum);           // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
    lcd.print(" ");                           // พิมพ์ข้อความ
    Serial.println("Cals : " + String(Cals)); // พิมพ์ข้อความ
    delayMicroseconds(1000);
  }
}
void SetupLCD()
{
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(0, 0);          // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print(""); // พิมพ์ข้อความ
  lcd.setCursor(2, 1);          // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("");  // พิมพ์ข้อความ "arduinoall.com"
  lcd.setCursor(0, 2);          // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print(""); // พิมพ์ข้อความ
  lcd.setCursor(2, 3);          // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("");  // พิมพ์ข้อความ "arduinoall.com"
}


#endif