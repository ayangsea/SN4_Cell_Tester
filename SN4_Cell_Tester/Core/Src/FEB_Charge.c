// ******************************** Includes and External ********************************

#include "FEB_Charge.h"

// ******************************** Functions ********************************

void FEB_Charge_Action() {

	//TODO: If done charging
	FEB_SM_Set_Current_State(FEB_SM_ST_DISCHARGE);
}
