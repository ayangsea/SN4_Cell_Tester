#ifndef INC_FEB_MAIN_H_
#define INC_FEB_MAIN_H_

// ******************************** Includes and External ********************************

#include "main.h"
#include "FEB_Charge.h"
#include "FEB_Discharge.h"
#include "FEB_Constant.h"
#include "FEB_Relay.h"
#include <stdbool.h>

// ********************************** Functions **********************************

void FEB_Main_Setup(void);
void FEB_Main_Loop(void);
void FEB_Main_Check_Status(void);

#endif /* INC_FEB_MAIN_H_ */
