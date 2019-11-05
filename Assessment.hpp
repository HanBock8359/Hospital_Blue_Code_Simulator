/**
 * Assessment.cpp
 * PURPOSE: This file is subclass of Station
 */

#include "Station.hpp"

#ifndef ASSESSMENT_HPP_
#define ASSESSMENT_HPP_

class Assessment : public Station{
	private:
		Queue* waitLine;
	public:
		Assessment(int numAssessmentNurses);
		virtual ~Assessment();
		
		Queue* getWaitLine();
		void printQueue();
		
		void enterStation(ListItem* item);
		Patient* exitStation();
		void enterWaitList(ListItem* item);
		Patient* exitWaitList();
	
		void print();
};

#endif /* ASSESSMENT_HPP_ */
