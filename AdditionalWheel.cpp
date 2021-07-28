
#include "AdditionalWheel.h"
#include "ADC.h"
#include "ErrorCollector.h"

AdditionalWheel::AdditionalWheel()
	:Actuator(5.2, 48)
	,m_enable(false)
	,m_current(0.0)
{}

 void AdditionalWheel::SetADC(int index, float adc)
 {
	 if(index == ADC::ADDITIONAL_WHEEL_CURRENT)
	 {
		 m_current = m_current * 0.8 + 0.2 * adc / m_coefficientADC;
		 if(m_current > m_maxCurrent)
		 {
			 ErrorCollector::instance().SetError(ErrorCollector::OVERCURRENT_ADDITIONAL_WHEEL);
			 m_state = ActuatorsController::STOP;
		 }
	 }
	 else if(index == ADC::ADDITIONAL_WHEEL_SENS)
	 {
		 m_newdutyCycle = 0;
		if(m_state == ActuatorsController::GOES_UP)
		{
			//some code
		}
		else if(m_state == ActuatorsController::GOES_DOWN)
		{
			m_newdutyCycle = MAX_PWM;
			//some code
		}
	 }
 }

void AdditionalWheel::Update(int currentDriveModel, bool isManual)
{
	//some code
}

