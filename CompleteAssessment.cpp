/**
 * CompleteAssessment.cpp
 * PURPOSE: This file is the subclass of Event class
 */
#include "CompleteAssessment.hpp"

CompleteAssessment::CompleteAssessment(Patient* patient, int time) : Event(patient, time){
	// TODO Auto-generated constructor stub

}

CompleteAssessment::~CompleteAssessment() {
	// TODO Auto-generated destructor stub
}

void CompleteAssessment::print(){
	cout << "Time     " << getTime();
	cout << " : Patient     " << getPatient()->getId();
	
	if(getPatient()->getBloodTest()){
		if(getPatient()->getWaiting()){
			cout << " completes assessment, assigned priority of " << getPatient()->getPriority() << ", added to the wait list of blood work." << endl;
		}
		else{
			cout << " completes assessment, assigned priority of " << getPatient()->getPriority() << ", scheduled for blood work." << endl;
		}
	}
	else if(getPatient()->getXrayTest()){
		if(getPatient()->getWaiting()){
			cout << " completes assessment, assigned priority of " << getPatient()->getPriority() << ", added to the wait list of xray." << endl;
		}
		else{
			cout << " completes assessment, assigned priority of " << getPatient()->getPriority() << ", scheduled for xray." << endl;
		}
	}
	else{
		if(getPatient()->getWaiting()){
			cout << " completes assessment, assigned priority of " << getPatient()->getPriority() << ", added to the wait list of treatment." << endl;
		}
		else{
			cout << " completes assessment, assigned priority of " << getPatient()->getPriority() << ", scheduled for treatment." << endl;
		}
	}
//	
}
