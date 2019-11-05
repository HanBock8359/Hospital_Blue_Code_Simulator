/**
 * Discharge.hpp
 * PURPOSE: This file is the subclass of Event class
 */

#include "StartAssessment.hpp"

StartAssessment::StartAssessment(Patient* patient, int time) : Event(patient, time){
	// TODO Auto-generated constructor stub

}

StartAssessment::~StartAssessment() {
	// TODO Auto-generated destructor stub
}

void StartAssessment::print(){
	cout << "Time     " << getTime();
	cout << " : Patient     " << getPatient()->getId();
	cout << " begins assessment of length " << getPatient()->getAssessmentTime() << "." << endl;

}
