#include "header.h"

int main()
{
        
 assert(batteryIsOk(40, 45, 0.7));//All okay

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
 return 0;
}
