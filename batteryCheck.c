
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