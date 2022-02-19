#ifndef BATTERYCHECK_H
#define BATTERYCHECK_H
int batteryIsOk(float temperature, float soc, float chargeRate);
int batteryTempCheck(float temperature);
int batterySocCheck(float soc);
int batteryChargerateCheck(float chargeRate);
#endif