#ifndef HelpCalculate
#define HelpCalculate
#include "HelpLibary.h"

float CalDataSetToPwm(float TempNum);

float CalDataSetToPwm( float TempSetCut)
{ Serial.print("CalDataPwm");
    Serial.println(TempSetCut);
    float CalDataPwm = 800*((TempSetCut*100)/((3.146*2)*0.48673));
    Serial.print("CalDataPwm");
    Serial.println(CalDataPwm);
    return(CalDataPwm); 
}
float CalPWMToM( float TempPWM){
 float CalDataM = (TempPWM/800)*((3.146 * 2) * 0.487)/100 ;
    Serial.print("CalDataM");
    Serial.println(CalDataM);
    return(CalDataM); 
}



#endif