#ifndef INC_FEB_SM_H_
#define INC_FEB_SM_H_

// ******************************** Includes ********************************

#include "FEB_Relay.h"

// ******************************** Enum & Struct ********************************

//List of states
typedef enum {
	FEB_SM_ST_IDLE,
	FEB_SM_ST_CHARGE,
	FEB_SM_ST_DISCHARGE
} FEB_SM_ST_t;

//Transitions
typedef struct {
	FEB_SM_ST_t curr_state;
	void (* action) (void);
	FEB_SM_ST_t next_state;
} FEB_SM_Transition_t;

// ******************************** Functions ********************************

void FEB_SM_Init(void);
FEB_SM_ST_t FEB_SM_Set_Current_State(FEB_SM_ST_t next_state);
FEB_SM_ST_t FEB_SM_Get_Current_State(void);

#endif /* INC_FEB_SM_H_ */
