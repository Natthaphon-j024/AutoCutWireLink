#ifndef HelpLCD
#define HelpLCD

#include "HelpLibary.h"

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);
// LiquidCrystal_I2C lcd(0x3F, 16, 2);

void LCDSelectMainMode(int temp);
void LCDSetupMode(int temp, int Location);
void SetupLCD();
void LCD_ShowStartRun(String temp);
void ClsLCD(int BanTunNum);
void LCD_Setting(String temp)
{

  lcd.clear();
  lcd.setCursor((21 - temp.length()) / 2, 0);                    // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print(String(temp));                                       // พิมพ์ข้อความ
  lcd.setCursor(5, 1);                                           // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Cut:" + String(SetCut.toFloat() / 100, 2) + " m."); // พิมพ์ข้อความ "arduinoall.com"
  lcd.setCursor(3, 2);                                           // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Count:" + String(Count) + " w.");                   // พิมพ์ข้อความ "arduinoall.com"

  delayMicroseconds(1000);
}
void LCD_ShowStartRun(String temp)
{
  lcd.clear();
  lcd.setCursor((21 - temp.length()) / 2, 0);                             // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print(String(temp));                                                // พิมพ์ข้อความ
  lcd.setCursor(3, 1);                                                    // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Length:" + String(00.00) + " m.");                           // พิมพ์ข้อความ "arduinoall.com"
  lcd.setCursor(6, 2);                                                    // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print("Cut:" + String(SetCut.toFloat() / 100, 2) + " m.");          // พิมพ์ข้อความ
  lcd.setCursor(4, 3);                                                    // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Count:" + String(Count) + "|" + String(stackCount) + " w."); // พิมพ์ข้อความ "arduinoall.com"
  delayMicroseconds(1000);
}
void LCD_ShowRun(String TempLength, String TempMode)
{
  if (OloLengthData != TempLength.length())
  {
    lcd.clear();
    lcd.setCursor((21 - TempMode.length()) / 2, 0); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
    lcd.print(String(TempMode));                    // พิมพ์ข้อความ
    lcd.setCursor(3, 1);                            // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
    lcd.print("Length:" + String(TempLength));
    lcd.setCursor(15, 1);
    lcd.print(" m.");                                                       // พิมพ์ข้อความ "arduinoall.com"
    lcd.setCursor(6, 2);                                                    // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
    lcd.print("Cut:" + String(SetCut.toFloat() / 100, 2) + " m.");          // พิมพ์ข้อความ
    lcd.setCursor(4, 3);                                                    // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
    lcd.print("Count:" + String(Count) + "|" + String(stackCount) + " w."); // พิมพ์ข้อความ "arduinoall.com"
    OloLengthData = TempLength.length();
  }

  lcd.setCursor(3, 1); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Length:" + String(TempLength));
  lcd.setCursor(15, 1);
  lcd.print(" m.");
  lcd.setCursor(4, 3);                                                    // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("Count:" + String(Count) + "|" + String(stackCount) + " w."); // พิมพ์ข้อความ "arduinoall.com"
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
  lcd.setCursor(0, 0); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print("");       // พิมพ์ข้อความ
  lcd.setCursor(2, 1); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("");       // พิมพ์ข้อความ "arduinoall.com"
  lcd.setCursor(0, 2); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 0 บรรทัดที่ 0
  lcd.print("");       // พิมพ์ข้อความ
  lcd.setCursor(2, 3); // กำหนดตำแหน่งเคอร์เซอร์ที่ แถวที่ 2 บรรทัดที่ 1
  lcd.print("");       // พิมพ์ข้อความ "arduinoall.com"
}

#endif