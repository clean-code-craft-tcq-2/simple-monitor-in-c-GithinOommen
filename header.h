#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <assert.h>
#include "thresholdCheck.h"
#include "batteryCheck.h"
#include "language.h"

#define ENGLISH 0
#define GERMAN 1 

#define Language_SET ENGLISH

#define PARA_TEMP   0
#define PARA_SOC    1
#define PARA_CHARGE 2

#define TEMP_HIGH 45
#define TEMP_LOW 0 
#define SOC_HIGH 80
#define SOC_LOW 20
#define CHARGE_RATE_HIGH 0.8
#define CHARGE_RATE_LOW 0
#define BUFFER 0.05

#define ERR_LOW                    0x01
#define ERR_HIGH                   0x00

#define ALERT                    0x01
#define WARNING                  0x02

#endif