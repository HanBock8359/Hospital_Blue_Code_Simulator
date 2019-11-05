/**
 * CompleteXray.hpp
 * PURPOSE: This file is the subclass of Event class
 */

#include "Event.hpp"

#ifndef COMPLETEXRAY_HPP_
#define COMPLETEXRAY_HPP_

class CompleteXray : public Event{
public:
	CompleteXray(Patient* patient, int time);
	virtual ~CompleteXray();

	void print();
};

#endif /* COMPLETEXRAY_HPP_ */
