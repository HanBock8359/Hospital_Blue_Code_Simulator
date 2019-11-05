/**
 * Discharge.cpp
 * PURPOSE: This file is the subclass of Event class
 */
#include "Event.hpp"

#ifndef DISCHARGE_HPP_
#define DISCHARGE_HPP_

class Discharge : public Event{
public:
	Discharge(Patient* patient, int time);
	virtual ~Discharge();

	void print();
};

#endif /* DISCHARGE_HPP_ */
