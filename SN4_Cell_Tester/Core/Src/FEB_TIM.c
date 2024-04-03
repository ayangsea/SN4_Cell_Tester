// ******************************** Includes and External ********************************

#include "FEB_TIM.h"

extern TIM_HandleTypeDef htim13;
extern UART_HandleTypeDef huart2;

// ******************************** Functions *******************************

void FEB_TIM_Start_Timer() {
	HAL_TIM_Base_Start_IT(&htim13);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim == &htim13) {
		//FEB_ADC_PollADC();
		char errmsg[256];
		sprintf(errmsg, "Interrupt\n");
		HAL_UART_Transmit(&huart2, (uint8_t*) errmsg, strlen(errmsg), 100);
	}
}
