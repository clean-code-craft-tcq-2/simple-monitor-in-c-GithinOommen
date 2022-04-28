#include "header.h"
int batteryTempCheck(float temperature)
{
        int FailureAlert,Lowerstatus, HigherStatus=0;
        int errorcode_1=0;
        float lowlimit = TEMP_LOW, higlimit = TEMP_HIGH;
       Lowerstatus= checkLowLimit(temperature,lowlimit,higlimit,&errorcode_1);
       if(Lowerstatus==0)
       {
       HigherStatus=checkHighLimit(temperature,lowlimit,higlimit,&errorcode_1);
       }
        FailureAlert= FailureAlertCheck(Lowerstatus,HigherStatus);
        int limitBreach=PrintDecision(Lowerstatus,HigherStatus);
// printf("\n alert: %d",limitBreach);
 if(limitBreach)
 {
  print(Language_SET,PARA_TEMP, FailureAlert,errorcode_1);
 }
 return (!(limitBreach));
}
int FailureAlertCheck(int Low, int High)
{
        if(Low == ALERT|| High == ALERT)
 {
       return 1;
 } 
 return 0;
}

int PrintDecision(int lowstatus, int highstatus)
{
 if(lowstatus|| highstatus)
 {
         return 1;
 }
 return 0;
}
