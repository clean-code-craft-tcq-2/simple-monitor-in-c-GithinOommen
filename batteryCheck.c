
#include "parameters.h"

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
   int parameter_index =PARA_CHARGE;
    int FailureAlert,fault,result =0;
   if(chargeRate > CHARGE_RATE_HIGH_WARNING && chargeRate < CHARGE_RATE_HIGH) {
       fault=ERR_HIGH;
        result= 1;
  }
  else if(chargeRate>CHARGE_RATE_HIGH)
  {
      FailureAlert = 1;
      fault = ERR_HIGH;
  }
  else
  {
      result= 1;
  }
    if(!result){
  print(Language_SET,parameter_index, FailureAlert,fault);
   }
  return result;
}
