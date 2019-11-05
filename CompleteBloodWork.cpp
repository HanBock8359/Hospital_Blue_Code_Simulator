/**
 * CompleteBloodWork.cpp
 * PURPOSE: This file is the subclass of Event class
 */

#include "CompleteBloodWork.hpp"

CompleteBloodWork::CompleteBloodWork(Patient* patient, int time) : Event(patient, time){
	// TODO Auto-generated constructor stub

}

CompleteBloodWork::~CompleteBloodWork() {
	// TODO Auto-generated destructor stub
}

void CompleteBloodWork::print(){
	cout << "Time     " << getTime();
	cout << " : Patient     " << getPatient()->getId();
	
	if(getPatient()->getXrayTest()){
		if(getPatient()->getWaiting()){
			cout << " completes blood work. Added to the wait list of xray." << endl;
		}
		else{
			cout << " completes blood work. Scheduled for xray." << endl;
		}
	}
	else{
		if(getPatient()->getWaiting()){
			cout << " completes blood work. Added to the wait list of treatment." << endl;
		}
		else{
			cout << " completes blood work. Scheduled for treatment." << endl;
		}
	}
}
