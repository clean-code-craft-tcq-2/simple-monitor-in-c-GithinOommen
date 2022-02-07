#include <stdio.h>
#include <assert.h>

#define TEMP_HIGH 45
#define TEMP_LOW 0 

#define SOC_HIGH 80
#define SOC_LOW 20

#define CHARGE_RATE_HIGH 0.8

void print (float value, char* paraName){
    printf("%s is out of range! read value is : %f\n", paraName ,value);
}
int batteryTempCheck(float temperature){
  if(temperature < TEMP_LOW || temperature > TEMP_HIGH) {
    print(temperature, "Temperature");
    return 0;
  }
    else
    {
    return 1;
    }
}
int batterySocCheck(float soc){
   if(soc < SOC_LOW || soc > SOC_HIGH) {
    print(soc,"State of Charge");
    return 0;
   }
   else
   {
       return 1;
   }
}
int batteryChargerateCheck(float chargeRate){
   if(chargeRate > CHARGE_RATE_HIGH) {
    print(chargeRate, "Charge Rate");
    return 0;
  }
  else
  {
      return 1;
  }
}
int batteryIsOk(float temperature, float soc, float chargeRate) {
    
    batteryTempCheck(temperature);
    batterySocCheck(soc);
    batteryChargerateCheck(chargeRate);
    
}
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
