#ifndef INC_FEB_ADC_H_
#define INC_FEB_ADC_H_

// ********************************** Includes **********************************

#include "stm32f4xx_hal.h"
#include <stdint.h>
#include "main.h"

// ********************************** Functions **********************************

void FEB_ADC_PollADC(void);
void FEB_ADC_Convert_Values(void);
void FEB_ADC_Select_Current(void);
void FEB_ADC_Select_Voltage(void);
void FEB_ADC_Select_Temp1(void);
void FEB_ADC_Select_Temp2(void);
void FEB_ADC_Select_Temp3(void);


#endif /* INC_FEB_ADC_H_ */
