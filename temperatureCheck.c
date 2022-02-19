
#include "parameters.h"
int batteryTempCheck(float temperature){
    
    int result = 0;
    int parameter_index,FailureAlert,fault,status=0;
    parameter_index =PARA_TEMP;
    
    if(temperature < TEMP_LOW || temperature > TEMP_HIGH) 
    {
        FailureAlert = 1;
        status=TemperatureAlertCheck(temperature,&fault);
        result= 0;
    }
    else
    {
        FailureAlert = 0;
        status=TemperatureWarningCheck(temperature,&fault);
        result= 1;
    }

   if(status)
    {
    print(Language_SET,parameter_index, FailureAlert,fault);
    }
    return result;
}
int TemperatureAlertCheck(float temperature, int* fault)
{
 int faultcode=0;
    if(temperature < TEMP_LOW)
    {
         *fault = ERR_LOW;
    }
    else
    {
        *fault = ERR_HIGH;
    }
    return 1;
}

int TemperatureWarningCheck(float temperature, int* fault)
{
    int faultcode=1;
   if(temperature<TEMP_LOW_WARNING)
  {
      *fault = ERR_LOW;
  }
    else if(temperature>TEMP_HIGH_WARNING)
  {
      *fault = ERR_HIGH;
  }
  else
  {
      faultcode=0;
  }
  return faultcode;
}