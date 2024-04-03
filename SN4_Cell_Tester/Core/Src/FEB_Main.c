// ******************************** Includes ********************************

#include "FEB_Main.h"

extern UART_HandleTypeDef huart2;

// ******************************** Functions ********************************

void FEB_Main_Setup() {
	FEB_TIM_Start_Timer();
}

bool chargeMode = true;

void FEB_Main_Loop() {

	//TODO: Remove, for debug
//	char errmsg[256];
//	sprintf(errmsg, "Main Loop\n");
//	HAL_UART_Transmit(&huart2, (uint8_t*) errmsg, strlen(errmsg), 100);
//	HAL_Delay(100);

	if (chargeMode) {
		FEB_Charge_Action();
	} else {
		FEB_Discharge_Action();
	}
	FEB_Main_Check_Status();
}

void FEB_Main_Check_Status() {
	if ((FEB_ADC_Get_Voltage() > FEB_CONST_CELL_MAX_VOLT_V) ||
		(FEB_ADC_Get_Voltage() < FEB_CONST_CELL_MIN_VOLT_V) ||
		(!chargeMode && FEB_ADC_Get_Current() > FEB_CONST_MAX_CURRENT_DC_A) ||
		(chargeMode && FEB_ADC_Get_Current() > FEB_CONST_MAX_CURRENT_CH_A) ||
		(chargeMode && FEB_ADC_Get_Temp1() > FEB_CONST_CELL_MAX_TEMP_CH_C) ||
		(chargeMode && FEB_ADC_Get_Temp2() > FEB_CONST_CELL_MAX_TEMP_CH_C) ||
		(chargeMode && FEB_ADC_Get_Temp3() > FEB_CONST_CELL_MAX_TEMP_CH_C) ||
		(!chargeMode && FEB_ADC_Get_Temp1() < FEB_CONST_CELL_MIN_TEMP_CH_C) ||
		(!chargeMode && FEB_ADC_Get_Temp2() < FEB_CONST_CELL_MIN_TEMP_CH_C) ||
		(!chargeMode && FEB_ADC_Get_Temp3() < FEB_CONST_CELL_MIN_TEMP_CH_C)) {

		//Open safety switch
		FEB_Relay_Safety_Open();

	}
}
