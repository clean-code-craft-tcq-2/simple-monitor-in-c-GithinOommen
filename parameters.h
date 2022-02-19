#ifndef PARAMETERS_H_INCLUDED
#define PARAMETERS_H_INCLUDED
#include<stdio.h>
#include <assert.h>
#include "language.h"
#include "batteryCheck.h"
#include "temperatureCheck.h"
#include "SOCCheck.h"

#define ENGLISH 0
#define GERMAN 1 

#define Language_SET ENGLISH


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

#endif