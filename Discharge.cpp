/**
 * Discharge.cpp
 * PURPOSE: This file is the subclass of Event class
 */

#include "Discharge.hpp"

Discharge::Discharge(Patient* patient, int time) : Event(patient, time){
	// TODO Auto-generated constructor stub

}

Discharge::~Discharge() {
	// TODO Auto-generated destructor stub
}

void Discharge::print(){
	cout << "Time     " << getTime();
	cout << " : Patient     " << getPatient()->getId();
	cout << " discharged at time " << getTime() << endl;
}
