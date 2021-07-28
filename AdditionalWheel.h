/*
 * AdditionalWheel.h
 *
 *  Created on: 12 но€б. 2020 г.
 *      Author: efanov
 */

#ifndef INC_ADDITIONALWHEEL_H_
#define INC_ADDITIONALWHEEL_H_
#include "main.h"
#include "Actuator.h"
#include "CallBack.h"

class AdditionalWheel : public CallBack, public Actuator
{
public:
	AdditionalWheel();
	virtual ~AdditionalWheel() {}
	virtual void SetADC(int index, float adc) override;
	float GetCurrent() { return m_current; }

	void Update(int currentDriveModel, bool isManual = false) override;
	void SetActiveAdditionalWheel(bool active) { m_enable = active; }
	bool Enable() { return m_enable; }

private:
	bool m_enable;
	bool m_current;
};

#endif /* INC_ADDITIONALWHEEL_H_ */
