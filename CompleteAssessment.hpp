/**
 * CompleteAssessment.hpp
 * PURPOSE: This file is the subclass of Event class
 */
#include "Event.hpp"

#ifndef COMPLETEASSESSMENT_HPP_
#define COMPLETEASSESSMENT_HPP_

class CompleteAssessment : public Event{
public:
	CompleteAssessment(Patient* patient, int time);
	virtual ~CompleteAssessment();

	void print();
};

#endif /* COMPLETEASSESSMENT_HPP_ */
