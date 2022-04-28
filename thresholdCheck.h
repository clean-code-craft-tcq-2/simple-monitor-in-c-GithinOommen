#ifndef THRESHOLDCHECK_H
#define THRESHOLDCHECK_H
extern int checkLowLimit(float input, float lowLimit, float highLimit, int* error_Code);
extern int checkHighLimit(float input, float lowLimit, float highLimit, int* error_Code) ;
extern int FailureAlertCheck(int Low, int High);
extern int PrintDecision(int lowstatus, int highstatus);
#endif
