/**
 * StartTreatment.hpp
 * PURPOSE: This file is the subclass of Event class
 */
#include "Event.hpp"

#ifndef STARTTREATMENT_HPP_
#define STARTTREATMENT_HPP_

class StartTreatment : public Event{
public:
	StartTreatment(Patient* patient, int time);
	virtual ~StartTreatment();

	void print();
};

#endif /* STARTTREATMENT_HPP_ */
