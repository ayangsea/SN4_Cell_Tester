// ******************************** Includes & External ********************************

#include "FEB_Relay.h"

// ******************************** Relay Control ********************************

void FEB_Relay_Charge_Open() {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);
}

void FEB_Relay_Charge_Close() {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);
}

void FEB_Relay_Discharge_Open() {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
}

void FEB_Relay_Discharge_Close() {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
}

void FEB_Relay_Safety_Open() {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
}

void FEB_Relay_Safety_Close() {
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
}
