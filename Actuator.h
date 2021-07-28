

#ifndef ACTUATOR_H_
#define ACTUATOR_H_

#include <main.h>
#include "ActuatorsController.h"

class Actuator
{
public:
	Actuator(float maxCurrent, float coefficientADC);

	virtual ~Actuator();
	virtual void Update(int currentDriveModel, bool isManual = false) = 0;

	void SetState(ActuatorsController::ActuatorState state);
	void ResetPWM();
	void SetPWM();

	ActuatorsController::ActuatorState GetState() { return m_state; }

protected:
	ActuatorsController::ActuatorState   m_state;
	int 			m_dutyCycle;
	int				m_newdutyCycle;
	float 			m_maxCurrent;
	float 			m_coefficientADC;
};

#endif

