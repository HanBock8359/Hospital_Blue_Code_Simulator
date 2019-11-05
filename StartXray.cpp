/**
 * StartXray.cpp
 * PURPOSE: This file is the subclass of Event class
 */
#include "StartXray.hpp"

StartXray::StartXray(Patient* patient, int time) : Event(patient, time){
	// TODO Auto-generated constructor stub

}

StartXray::~StartXray() {
	// TODO Auto-generated destructor stub
}

void StartXray::print(){
	cout << "Time     " << getTime();
	cout << " : Patient     " << getPatient()->getId();
	cout << " begins Xray." << endl;
}
