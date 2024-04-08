// ******************************** Includes & External ********************************

#include "FEB_SM.h"

// ******************************** Static Function Declaration ********************************

static void idle_to_charge(void);
static void idle_to_discharge(void);
static void charge_to_discharge(void);
static void discharge_to_charge(void);
static void shutdown(void);

// ******************************** Static Variables ********************************

static FEB_SM_ST_t curr_state;

#define NUM_TRANSITIONS 6

static FEB_SM_Transition_t transitions[NUM_TRANSITIONS] = {
		{FEB_SM_ST_IDLE, idle_to_charge, FEB_SM_ST_CHARGE},
		{FEB_SM_ST_IDLE, idle_to_discharge, FEB_SM_ST_DISCHARGE},
		{FEB_SM_ST_CHARGE, charge_to_discharge, FEB_SM_ST_DISCHARGE},
		{FEB_SM_ST_DISCHARGE, discharge_to_charge, FEB_SM_ST_CHARGE},
		{FEB_SM_ST_CHARGE, shutdown, FEB_SM_ST_IDLE},
		{FEB_SM_ST_DISCHARGE, shutdown, FEB_SM_ST_IDLE},
};

// ******************************** Public Interface ********************************

void FEB_SM_Init() {
	curr_state = FEB_SM_ST_IDLE;
	FEB_Relay_Safety_Open();
	FEB_Relay_Charge_Open();
	FEB_Relay_Discharge_Open();
}

FEB_SM_ST_t FEB_SM_Get_Current_State() {
	return curr_state;
}

//Return 0 if state switch successful, 1 otherwise
uint8_t FEB_SM_Set_Current_State(FEB_SM_ST_t next_state) {
	for (uint8_t i = 0; i < NUM_TRANSITIONS; i++) {
		if (transitions[i].curr_state == curr_state &&
			transitions[i].next_state == next_state) {
			transitions[i].action();
			return 0;
		}
	}
	return 1;
}

// ******************************** Transition Functions ********************************

static void idle_to_charge() {
	FEB_Relay_Safety_Close();
	FEB_Relay_Charge_Close();
}

static void idle_to_discharge() {
	FEB_Relay_Safety_Close();
	FEB_Relay_Discharge_Close();
}

static void charge_to_discharge() {
	FEB_Relay_Charge_Open();
	FEB_Relay_Discharge_Close();
}

static void discharge_to_charge() {
	FEB_Relay_Discharge_Open();
	FEB_Relay_Charge_Close();
}

static void shutdown() {
	FEB_Relay_Safety_Open();
	FEB_Relay_Charge_Open();
	FEB_Relay_Discharge_Open();
}
