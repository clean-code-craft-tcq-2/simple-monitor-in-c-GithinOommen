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
       FailureAlert= FailureAlertCheck(Lowerstatus,HigherStatus);
       int limitBreach=PrintDecision(Lowerstatus,HigherStatus);
 if(limitBreach)
 {
  print(Language_SET,PARA_SOC, FailureAlert,errorcode_1);
 }
  return (!(limitBreach));
}
