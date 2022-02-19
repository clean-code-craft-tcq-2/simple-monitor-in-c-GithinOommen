#ifndef SOCCHECK_H_INCLUDED
#define SOCCHECK_H_INCLUDED
int SOCAlertCheck(float soc, int* fault);
int SOCWarningCheck(float soc, int *fault);
#endif
