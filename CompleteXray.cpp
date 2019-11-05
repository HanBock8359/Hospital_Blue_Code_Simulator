/**
 * CompleteXray.cpp
 * PURPOSE: This file is the subclass of Event class
 */

#include "CompleteXray.hpp"

CompleteXray::CompleteXray(Patient* patient, int time) : Event(patient, time){
	// TODO Auto-generated constructor stub

}

CompleteXray::~CompleteXray() {
	// TODO Auto-generated destructor stub
}

void CompleteXray::print(){
	cout << "Time     " << getTime();
	cout << " : Patient     " << getPatient()->getId();
	
	if(getPatient()->getBloodTest()){
		if(getPatient()->getWaiting()){
			cout << " completes Xray. Added to the wait list of blood work." << endl;
		}
		else{
			cout << " completes Xray. Scheduled for blood work." << endl;
		}
	}
	else{
		if(getPatient()->getWaiting()){
			cout << " completes Xray. Added to the wait list of treatment." << endl;
		}
		else{
			cout << " completes Xray. Scheduled for treatment." << endl;
		}
	}
}

