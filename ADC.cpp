
#include "ADC.h"
#include "CallBack.h"
#include "main.h"


void ADC::Init(ADC_HandleTypeDef * hadc)
{
	assert_param(hadc != nullptr);

	m_hadc = hadc;

	HAL_ADCEx_Calibration_Start(m_hadc);
	HAL_ADC_Start_DMA(m_hadc, (uint32_t*)&m_adcData, Elements::count);
}

void ADC::Run()
{
	if(m_needReadDataADC)
	{
		 HAL_ADC_Stop_DMA(m_hadc);
		 for(int i = 0; i < Elements::count; i++)
		 {
			 if(m_callBack[i] != nullptr)
			 {
				  m_callBack[i]->SetADC(i, m_adcData[i]);
			 }
		 }
		 m_needReadDataADC = false;
		 HAL_ADC_Start_DMA(m_hadc, (uint32_t*)&m_adcData, Elements::count);
	}
}

void ADC::RegisterClass(uint8_t index, CallBack * callBack)
{
	assert_param( index < Elements::count || callBack != nullptr);

	m_callBack[index] = callBack;
}
