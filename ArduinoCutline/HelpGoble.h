#ifndef HelpGoble
#define HelpGoble

#define InButtonlift A0
#define InButtonright A1
#define InButtonOK A2
#define InButtonCancls A3

char *ModeMainName[] = {"Standby","Start" , "Setting"};
/*  
{   10,       20       , 30       , 100}
{"SetupSC","SetcpCS" ,"SetupCC","SAVE" }
*/
char *ModeSetupName[] = {"SetupSC" ,"SetupCC","SAVE" };
//char *DataSet[] = {"123","132","1232" ,"123"};
int NumMode = 0;
bool ButtonUP,ButtonDow,ButtonOK,ButtonCancls;
// pin stepPing Motor and value 
#define pulPin 5 // Pw cotro speed stepping Motor
#define dirPin 4 // dir stepping Motor left or right this High  and low 
#define enaPin 3  //on off dir
float cord = 11;
int CurrentAngle = 0;
int Angle = 0;
int StepNum;
String ModeID = "Standby";
int SubModeSettingID = 0;
int OloLengthData = 20; 
long int sumCut;
long int PWMCut;
float PWMStapping;
String SetCut = "00.01";
String Count = "1";
int stackCount= 0;
int OlostackCount;
int ModeIDSet=0;
unsigned long timebBT = 0;
unsigned long settimeBT =500;

#endif