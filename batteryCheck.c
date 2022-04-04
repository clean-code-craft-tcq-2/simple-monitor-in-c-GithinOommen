
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
  print(Language_SET,PARA_CHARGE, FailureAlert,errorcode_1);
 }
 return (!(Lowerstatus|| HigherStatus));
}