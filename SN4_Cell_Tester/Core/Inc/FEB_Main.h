#ifndef INC_FEB_MAIN_H_
#define INC_FEB_MAIN_H_

// ******************************** Includes and External ********************************

#include "main.h"
#include "FEB_Charge.h"
#include "FEB_Discharge.h"
#include "FEB_Constant.h"
#include "FEB_Relay.h"
#include "FEB_TIM.h"
#include "FEB_SM.h"
#include <stdbool.h>

// ********************************** Functions **********************************

void FEB_Main_Setup(void);
void FEB_Main_Loop(void);
uint8_t FEB_Main_State(void);

#endif /* INC_FEB_MAIN_H_ */
