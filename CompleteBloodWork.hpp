/**
 * CompleteBloodWork.hpp
 * PURPOSE: This file is the subclass of Event class
 */

#include "Event.hpp"

#ifndef COMPLETEBLOODWORK_HPP_
#define COMPLETEBLOODWORK_HPP_

class CompleteBloodWork : public Event{
public:
	CompleteBloodWork(Patient* patient, int time);
	virtual ~CompleteBloodWork();

	void print();
};

#endif /* COMPLETEBLOODWORK_HPP_ */
