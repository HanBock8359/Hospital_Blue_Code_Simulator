/**
 * StartXray.hpp
 * PURPOSE: This file is the subclass of Event class
 */
#include "Event.hpp"

#ifndef STARTXRAY_HPP_
#define STARTXRAY_HPP_

class StartXray : public Event{
public:
	StartXray(Patient* patient, int time);
	virtual ~StartXray();

	void print();
};

#endif /* STARTXRAY_HPP_ */
