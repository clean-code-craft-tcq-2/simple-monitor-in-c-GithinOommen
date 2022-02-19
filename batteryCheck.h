#ifndef BATTERYCHECK_H_INCLUDED
#define BATTERYCHECK_H_INCLUDED

 int batteryTempCheck(float temperature);
 int batterySocCheck(float soc);
 int batteryIsOk(float temperature, float soc, float chargeRate);
 int batteryChargerateCheck(float temperature);
int ChargeAlertCheck(float temperature, int* fault);
int ChargeWarningCheck(float temperature, int *fault);
extern int parameter_index,FailureAlert,fault;
#endif
