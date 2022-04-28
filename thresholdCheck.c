#include "header.h"

int checkLowLimit(float input, float lowLimit, float highLimit, int* error_code)       
{   
        int result = 0;
	if (input  < lowLimit)
	{
	result = ALERT;
	}
	else if(input < (BUFFER *  highLimit)+lowLimit)
	{
	  result = WARNING;
	}

	*error_code = ERR_LOW;

	
    return result;
}
int checkHighLimit(float input, float lowLimit, float highLimit, int* error_code)       
{   int result = 0;
	if (input  > highLimit)
	{
	result = ALERT;
	}
	else if(input > (((1-BUFFER)) *  highLimit))
	{
	  result = WARNING;
	}
	
	*error_code = ERR_HIGH;

	
    return result;
}