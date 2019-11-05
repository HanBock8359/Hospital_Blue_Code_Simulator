/**
 * Treatment.hpp
 * PURPOSE: This file is subclass of Station
 */
#include "Station.hpp"

#ifndef TREATMENT_HPP_
#define TREATMENT_HPP_

class Treatment : public Station{
public:
	Treatment(int numDoctors);
	virtual ~Treatment();

	void printQueue();
	
	void print();
};

#endif /* TREATMENT_HPP_ */
