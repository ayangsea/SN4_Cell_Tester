// ******************************** Includes and External ********************************

#include "FEB_ADC.h"

extern ADC_HandleTypeDef hadc1;

// ******************************** Struct ********************************

typedef struct {
	float voltage_V;
	float current_A; //TODO: Figure out what units
	float temp1_C;
	float temp2_C;
	float temp3_C;

} battery_t;

static battery_t battery;
static uint16_t adc_val[5];

// ******************************** Functions *******************************

void FEB_ADC_PollADC() {

	//TODO: Remove, for testing w/ LED
	//HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);

	//Current
	FEB_ADC_Select_Current();
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1000);
	adc_val[0] = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	//Voltage
	FEB_ADC_Select_Voltage();
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1000);
	adc_val[1] = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	//Temp1
	FEB_ADC_Select_Temp1();
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1000);
	adc_val[2] = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	//Temp2
	FEB_ADC_Select_Temp2();
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1000);
	adc_val[3] = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	//Temp3
	FEB_ADC_Select_Temp3();
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1, 1000);
	adc_val[4] = HAL_ADC_GetValue(&hadc1);
	HAL_ADC_Stop(&hadc1);

	FEB_ADC_Convert_Values();

	FEB_ADC_Status();
}

void FEB_ADC_Convert_Values() {
	//TODO: Convert values
	battery.voltage_V = adc_val[1] * 3.3f / 4096.0f;
}

float FEB_ADC_Get_Voltage() {
	return battery.voltage_V;
}

float FEB_ADC_Get_Current() {
	return battery.current_A;
}

float FEB_ADC_Get_Temp1() {
	return battery.temp1_C;
}

float FEB_ADC_Get_Temp2() {
	return battery.temp2_C;
}

float FEB_ADC_Get_Temp3() {
	return battery.temp3_C;
}

void FEB_ADC_Status() {
	FEB_SM_ST_t state = FEB_SM_Get_Current_State();
	if ((FEB_ADC_Get_Voltage() > FEB_CONST_CELL_MAX_VOLT_V) ||
			(FEB_ADC_Get_Voltage() < FEB_CONST_CELL_MIN_VOLT_V) ||
			(state == FEB_SM_ST_DISCHARGE && FEB_ADC_Get_Current() > FEB_CONST_MAX_CURRENT_DC_A) ||
			(state == FEB_SM_ST_CHARGE && FEB_ADC_Get_Current() > FEB_CONST_MAX_CURRENT_CH_A) ||
			(FEB_ADC_Get_Temp1() > FEB_CONST_CELL_MAX_TEMP_DC_C) ||
			(FEB_ADC_Get_Temp2() > FEB_CONST_CELL_MAX_TEMP_DC_C) ||
			(FEB_ADC_Get_Temp3() > FEB_CONST_CELL_MAX_TEMP_DC_C)) {
		FEB_SM_Set_Current_State(FEB_SM_ST_IDLE);
	}
}

void FEB_ADC_Select_Current() {
	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  ADC_ChannelConfTypeDef sConfig = {0};
	  sConfig.Channel = ADC_CHANNEL_6;
	  sConfig.Rank = 1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

void FEB_ADC_Select_Voltage() {
	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  ADC_ChannelConfTypeDef sConfig = {0};
	  sConfig.Channel = ADC_CHANNEL_4;
	  sConfig.Rank = 1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

void FEB_ADC_Select_Temp1() {
	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  ADC_ChannelConfTypeDef sConfig = {0};
	  sConfig.Channel = ADC_CHANNEL_7;
	  sConfig.Rank = 1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

void FEB_ADC_Select_Temp2() {
	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  ADC_ChannelConfTypeDef sConfig = {0};
	  sConfig.Channel = ADC_CHANNEL_8;
	  sConfig.Rank = 1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
}

void FEB_ADC_Select_Temp3() {
	  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
	  */
	  ADC_ChannelConfTypeDef sConfig = {0};
	  sConfig.Channel = ADC_CHANNEL_9;
	  sConfig.Rank = 1;
	  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
	  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
	  {
	    Error_Handler();
	  }
}
