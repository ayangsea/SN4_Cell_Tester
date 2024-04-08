// ******************************** Includes ********************************

#include "FEB_Main.h"

extern UART_HandleTypeDef huart2;

// ******************************** Functions ********************************

void FEB_Main_Setup() {
	FEB_TIM_Start_Timer();
	FEB_SM_Init();

	FEB_ADC_PollADC();
	//TODO: if cell not charged
	FEB_SM_Set_Current_State(FEB_SM_ST_CHARGE);

	//TODO: else
	FEB_SM_Set_Current_State(FEB_SM_ST_DISCHARGE);
}

void FEB_Main_Loop() {


	//TODO: Remove, for debug
//	char errmsg[256];
//	sprintf(errmsg, "Main Loop\n");
//	HAL_UART_Transmit(&huart2, (uint8_t*) errmsg, strlen(errmsg), 100);
//	HAL_Delay(100);

	if (FEB_SM_Get_Current_State() == FEB_SM_ST_CHARGE) {
		FEB_Charge_Action();
	} else if (FEB_SM_Get_Current_State() == FEB_SM_ST_DISCHARGE){
		FEB_Discharge_Action();
	}
}
