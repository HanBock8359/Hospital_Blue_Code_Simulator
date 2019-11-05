/**
 * Arrival.cpp
 * PURPOSE: This file is subclass of Event
 */

#include "Arrival.hpp"

Arrival::Arrival(Patient* patient, int time) : Event(patient, time){
	// TODO Auto-generated constructor stub
}

Arrival::~Arrival() {
	// TODO Auto-generated destructor stub
}

//this method prints the patient information along with time
void Arrival::print(){
	cout << "Time     " << getTime();
	cout << " : Patient     " << getPatient()->getId();

	if(!getPatient()->getWaiting()){
		cout << " arrives in ED. Assessment nurse is free. Starting the assessment." << endl;
	}
	else{
		cout << " arrives in ED. Assessment nurse is busy. Added to the wait list." << endl;
	}
	
}
