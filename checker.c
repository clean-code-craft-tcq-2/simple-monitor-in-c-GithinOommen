#include <stdio.h>
#include <assert.h>


#define GERMAN 0
#define ENGLISH 1
int language= GERMAN;

#define PARA_TEMP   0
#define PARA_SOC    1
#define PARA_CHARGE 2

#define TEMP_HIGH 45
#define TEMP_LOW 0 
#define TEMP_HIGH_WARNING (TEMP_HIGH * 0.95f) // warning tolerance at 5% of 80 = 4; warning at 80-4 = 76 which is 95% 80.
#define TEMP_LOW_WARNING ((TEMP_HIGH * 0.05f)+TEMP_LOW) // warning tolerance at 5% of 80 = 4; warning at 0+4 = 4 which is 5% 80

#define SOC_HIGH 80
#define SOC_LOW 20
#define SOC_HIGH_WARNING (SOC_HIGH * 0.95f)
#define SOC_LOW_WARNING ((SOC_HIGH * 0.05f) + SOC_LOW)

#define CHARGE_RATE_HIGH 0.8
#define CHARGE_RATE_HIGH_WARNING (CHARGE_RATE_HIGH * 0.95f)

#define ERR_LOW                    0x01
#define ERR_HIGH                   0x00
#define ERR_TEMP_LOW_WARNING            0x01
#define ERR_TEMP_HIGH_WARNING           0x00
#define ERR_SOC_LOW                     0x01
#define ERR_SOC_HIGH                    0x00
#define ERR_SOC_LOW_WARNING             0x01
#define ERR_SOC_HIGH_WARNING            0x00
#define ERR_CHARGE_RATE_HIGH            0x00
#define ERR_CHARGE_RATE_HIGH_WARNING    0x00



//void print (float value, int para_index);
void print (float value,int fault, int para_index, int FailureAlert,float ref){

char parameter[3][50] = {"Temperature","State of Charge","Charge Rate"};
char warning[2][50] = {"is approaching Higher limit","is approaching Lower limit"};
char alert[2][50] = {"is Higher than", "is Lower than"};

char parameter1[3][50] = {"Temperatur","Ladezustand","Ladestrom"};
char warning1[2][50] = {"nähert sich der höheren Grenze","nähert sich der unteren Grenze"};
char alert1[2][50] = {"ist höher als", "ist niedriger als"};

if(language == ENGLISH){
   // printf("%s is out of range! read value is : %f\n", paraName ,value);
   if(FailureAlert)
   {
    printf("\n%s %s %f\n ",parameter[para_index],alert[fault],ref);
    }
    else
    {
    printf("\n%s %s  \n",parameter[para_index],warning[fault]); 
    }
}
else
{
      if(FailureAlert)
   {
    printf("\n%s %s %f\n ",parameter1[para_index],alert1[fault],ref);
    }
    else
    {
    printf("\n%s %s  \n",parameter1[para_index],warning1[fault]); 
    } 
}
    
}
int parameter_index,FailureAlert,fault=0;
float ref=0;

int batteryTempCheck(float temperature){
    int result = 0;
  //  int fault = 0;
    parameter_index =PARA_TEMP;
    
  if(temperature < TEMP_LOW || temperature > TEMP_HIGH) {
    FailureAlert = 1;
    if(temperature < TEMP_LOW)
    {
         fault = ERR_LOW;
         ref=TEMP_LOW;
         
    }
    else
    {
        fault = ERR_HIGH;
        ref=TEMP_HIGH;
    }
   
  }
  else if(temperature<TEMP_LOW_WARNING)
  {
      FailureAlert = 0;
      fault = ERR_LOW;
  }
    else if(temperature>TEMP_HIGH_WARNING)
  {
      FailureAlert = 0;
      fault = ERR_HIGH;
  }
    else
    {
    result= 1;
    }
    if(!result)
    {
    print(temperature,fault, parameter_index,FailureAlert,ref);
    }
    return result;
}
int batterySocCheck(float soc){
    parameter_index =PARA_SOC;
    int result =0;
   if(soc < SOC_LOW || soc > SOC_HIGH) {
   FailureAlert=1;
   if(soc<SOC_LOW)
   {
       fault = ERR_LOW;
       ref=SOC_LOW;
   }
   else
   {
       fault=ERR_HIGH;
       ref=SOC_HIGH;
   }
   }
   else if(soc<SOC_LOW_WARNING)
   {
       FailureAlert = 0;
      fault = ERR_LOW;
      ref=SOC_LOW_WARNING;
   }
  
   else if(soc>SOC_HIGH_WARNING)
   {
       FailureAlert = 0;
      fault = ERR_HIGH;
      ref=SOC_HIGH_WARNING;
   }
   else
   {
       result= 1;
   }
   if(!result){
    print(soc,fault, parameter_index,FailureAlert,ref);
   }
    return result;
}
int batteryChargerateCheck(float chargeRate){
    parameter_index =PARA_CHARGE;
    int result =0;
   if(chargeRate > CHARGE_RATE_HIGH_WARNING && chargeRate < CHARGE_RATE_HIGH) {
       fault=ERR_HIGH;
       ref=CHARGE_RATE_HIGH_WARNING;
  }
  else if(chargeRate>CHARGE_RATE_HIGH)
  {
      FailureAlert = 1;
      fault = ERR_HIGH;
      ref=CHARGE_RATE_HIGH;
  }
  else
  {
      result= 1;
  }
    if(!result){
    print(chargeRate,fault, parameter_index,FailureAlert,ref);
   }
  return result;
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
    int tempStatus, socStatus, chargeRateStatus,result1;
    tempStatus =batteryTempCheck(temperature);
    socStatus = batterySocCheck(soc);
    chargeRateStatus = batteryChargerateCheck(chargeRate);
    
    result1=tempStatus && socStatus && chargeRateStatus;
//    printf("\n result1: %d",result1);
   // printf("tempStatus : %d\nsocStatus : %d\nchargeRateStatus : %d",tempStatus,socStatus,chargeRateStatus);
   //  return (batteryTempCheck(temperature) && batterySocCheck(soc) && batteryChargerateCheck(chargeRate));
     
}

int main() {
    

 assert(batteryIsOk(25, 45, 0.7));//All okay
 
 assert(!batteryIsOk(85, 45, 0.7));// Temp HIGH
 assert(!batteryIsOk(-1, 45, 0.7));// TEMP LOW
 assert(!batteryIsOk(2.1, 45, 0.7));// Lower warning 
 assert(!batteryIsOk(43, 45, 0.7));// Higher warning 
 
 assert(!batteryIsOk(25, 85, 0.7));// SOC HIGH
 assert(!batteryIsOk(25, 10, 0.7));// SOC LOW
 assert(!batteryIsOk(25, 23, 0.7));// Lower warning 
 assert(!batteryIsOk(25, 77, 0.7));// Higher warning
 
 assert(!batteryIsOk(50, 45, 0.9));// chargeRate HIGH
 assert(!batteryIsOk(25, 45, 0.77));// Higher warning

}
