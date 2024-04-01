#ifndef INC_FEB_RELAY_H_
#define INC_FEB_RELAY_H_

// ******************************** Includes and External ********************************

#include "stm32f4xx_hal.h"

// ******************************** Relay Control ********************************

void FEB_Relay_Charge_Open(void);
void FEB_Relay_Charge_Close(void);
void FEB_Relay_Discharge_Open(void);
void FEB_Relay_Discharge_Close(void);
void FEB_Relay_Safety_Open(void);
void FEB_Relay_Safety_Close(void);

#endif /* INC_FEB_RELAY_H_ */
