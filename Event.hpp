/**
 * Event.cpp
 * PURPOSE: This file is the subclass class of ListItem to implement nine different events
 */

#include "ListItem.hpp"
#include "Patient.hpp"
#include <iostream>
#include <string>
using namespace std;

#ifndef EVENT_HPP_
#define EVENT_HPP_

class Event : public ListItem{
	private:
		Patient* patient;
		int time;
		bool wait;
	public:
		Event();
		Event(const Event& e);
		Event(Patient* patient, int time);
		virtual ~Event();

		Patient* getPatient();
		void setPatient(Patient* patient);
		int getTime();
		void setTime(int time);

		void print();
};

#endif /* EVENT_HPP_ */
