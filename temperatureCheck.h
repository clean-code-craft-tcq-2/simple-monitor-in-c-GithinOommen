#ifndef TEMPERATURECHECK_H_INCLUDED
#define TEMPERATURECHECK_H_INCLUDED

int TemperatureAlertCheck(float temperature, int* fault);
int TemperatureWarningCheck(float temperature, int *fault);
#endif