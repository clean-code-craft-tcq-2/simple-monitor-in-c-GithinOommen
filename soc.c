#include "header.h"
int batterySocCheck(float soc)
{
        int FailureAlert,Lowerstatus, HigherStatus=0;
        int errorcode_1=0;
        float lowlimit = SOC_LOW, higlimit = SOC_HIGH;
       Lowerstatus= checkLowLimit(soc,lowlimit,higlimit,&errorcode_1);
       if(Lowerstatus==0)
       {
       HigherStatus=checkHighLimit(soc,lowlimit,higlimit,&errorcode_1);
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
  print(Language_SET,PARA_SOC, FailureAlert,errorcode_1);
 }
 return (!(Lowerstatus|| HigherStatus));
}