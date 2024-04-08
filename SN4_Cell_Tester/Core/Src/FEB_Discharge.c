// ******************************** Includes and External ********************************

#include "FEB_Discharge.h"

// ******************************** Functions ********************************

void FEB_Discharge_Action() {

	//TODO: If done discharging
	FEB_SM_Set_Current_State(FEB_SM_ST_CHARGE);
}
