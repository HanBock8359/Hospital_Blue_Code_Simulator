/**
 * Arrival.hpp
 * PURPOSE: This file is subclass of Event (interface)
 */

#include "Event.hpp"

#ifndef ARRIVAL_HPP_
#define ARRIVAL_HPP_

class Arrival : public Event {
	public:
		Arrival(Patient* patient, int time);
		virtual ~Arrival();

		void print();
};

#endif /* ARRIVAL_HPP_ */
