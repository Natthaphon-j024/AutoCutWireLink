#ifndef HelpCalculate
#define HelpCalculate
#include "HelpLibary.h"

void CalDataSetToPwm(String TypeName, float TempNum);

void CalDataSetToPwm(String TypeName, float TempNum)
{
    float CalDataPwm = ((3.142 * 2) * 0.55) * TempNum;
}




#endif