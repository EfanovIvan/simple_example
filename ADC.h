

#ifndef INC_ADC_H_
#define INC_ADC_H_
#include "main.h"

class CallBack;

class ADC
{

public:
	enum CallBackIndex : uint8_t
	{
		LW_CURRENT = 0,
		RW_CURRENT = 1,
		CHAIR_CURRENT = 2,
		PLATFORM_CURRENT = 3,
		LEFT_BRAKE = 4,
		RIGHT_BRAKE = 5,
		PLATFORM_SENS =6,
		BATTERY = 7,
		ADDITIONAL_WHEEL_SENS = 8,
		ADDITIONAL_WHEEL_CURRENT = 9
	};

	enum Elements : uint8_t { count = 10 };

	void Init(ADC_HandleTypeDef * hadc);
	void SetNeedReadDataADC(bool need) { m_needReadDataADC = need; }
	void Run();
	void RegisterClass(uint8_t index, CallBack * callBack);

private:

	ADC_HandleTypeDef * m_hadc;

	bool m_calcOffsetVolt;
	bool m_needReadDataADC;

	CallBack * m_callBack[Elements::count] = {0};
	volatile uint16_t m_adcData[Elements::count] = {0};

};

#endif
