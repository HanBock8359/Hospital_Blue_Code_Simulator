/**
 * StartBloodWork.hpp
 * PURPOSE: This file is the subclass of Event class
 */

#include "Event.hpp"

#ifndef STARTBLOODWORK_HPP_
#define STARTBLOODWORK_HPP_

class StartBloodWork : public Event{
public:
	StartBloodWork(Patient* patient, int time);
	virtual ~StartBloodWork();

	void print();
};

#endif /* STARTBLOODWORK_HPP_ */
