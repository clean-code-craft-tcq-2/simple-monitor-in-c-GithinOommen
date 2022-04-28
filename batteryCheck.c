
#include "header.h"


int batteryIsOk(float temperature, float soc, float chargeRate)
{
        int tempStatus, socStatus, chargeRateStatus,result1;
        tempStatus =batteryTempCheck(temperature);
        socStatus = batterySocCheck(soc);
        chargeRateStatus = batteryChargerateCheck(chargeRate);
        result1=tempStatus && socStatus && chargeRateStatus;
    return result1;
}

int batteryChargerateCheck(float chargeRate){        
        int FailureAlert,Lowerstatus, HigherStatus=0;
        int errorcode_1=0;
        float lowlimit = CHARGE_RATE_LOW, higlimit = CHARGE_RATE_HIGH;
       Lowerstatus= checkLowLimit(chargeRate,lowlimit,higlimit,&errorcode_1);
       if(Lowerstatus==0)
       {
       HigherStatus=checkHighLimit(chargeRate,lowlimit,higlimit,&errorcode_1);
       }
       FailureAlert= FailureAlertCheck(Lowerstatus,HigherStatus);
       int limitBreach=PrintDecision(Lowerstatus,HigherStatus);
 if(limitBreach)
 {
  print(Language_SET,PARA_SOC, FailureAlert,errorcode_1);
 }
  return (!(limitBreach));
}
