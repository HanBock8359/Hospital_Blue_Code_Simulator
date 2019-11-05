/**
 * StartAssessment.hpp
 * PURPOSE: This file is the subclass of Event class
 */

#include "Event.hpp"

#ifndef STARTASSESSMENT_HPP_
#define STARTASSESSMENT_HPP_

class StartAssessment : public Event{
public:
	StartAssessment(Patient* patient, int time);
	virtual ~StartAssessment();

	void print();
};

#endif /* STARTASSESSMENT_HPP_ */
