#include "parameters.h"

int batterySocCheck(float soc){
    
    int result = 0;
    int parameter_index,FailureAlert,fault,status=0;
    parameter_index =PARA_SOC;
    
    if(soc < SOC_LOW || soc > SOC_HIGH) 
    {
        FailureAlert = 1;
        status=SOCAlertCheck(soc,&fault);
        result= 0;
    }
    else
    {
        FailureAlert = 0;
        status=SOCWarningCheck(soc,&fault);
        result= 1;
    }

   if(status)
    {
    print(Language_SET,parameter_index, FailureAlert,fault);
    }
    return result;
    
}
int SOCAlertCheck(float soc, int* fault)
{
 int faultcode=0;
    if(soc < SOC_LOW)
    {
         *fault = ERR_LOW;
    }
    else
    {
        *fault = ERR_HIGH;
    }
    return 1;
}

int SOCWarningCheck(float soc, int* fault)
{
    int faultcode=1;
   if(soc<SOC_LOW_WARNING)
  {
      *fault = ERR_LOW;
  }
    else if(soc>SOC_HIGH_WARNING)
  {
      *fault = ERR_HIGH;
  }
  else
  {
      faultcode=0;
  }
  return faultcode;
}