/**
 * StartTreatment.cpp
 * PURPOSE: This file is the subclass of Event class
 */
#include "StartTreatment.hpp"

StartTreatment::StartTreatment(Patient* patient, int time) : Event(patient, time){
	// TODO Auto-generated constructor stub

}

StartTreatment::~StartTreatment() {
	// TODO Auto-generated destructor stub
}

void StartTreatment::print(){
	cout << "Time     " << getTime();
	cout << " : Patient     " << getPatient()->getId();
	cout << " starts treatment of length " << getPatient()->getTreatmentTime() << endl;
}
