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
 if(Lowerstatus == ALERT|| HigherStatus == ALERT)
 {
       FailureAlert = 1;
 }
 else
 {
         FailureAlert=0;
 }
  if(Lowerstatus|| HigherStatus)
 {
  print(Language_SET,PARA_TEMP, FailureAlert,errorcode_1);
 }
 return (!(Lowerstatus|| HigherStatus));
}