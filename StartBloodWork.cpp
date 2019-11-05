/**
 * StartBloodWork.cpp
 * PURPOSE: This file is the subclass of Event class
 */
#include "StartBloodWork.hpp"

StartBloodWork::StartBloodWork(Patient* patient, int time) : Event(patient, time){
	// TODO Auto-generated constructor stub

}

StartBloodWork::~StartBloodWork() {
	// TODO Auto-generated destructor stub
}

void StartBloodWork::print(){
	cout << "Time     " << getTime();
	cout << " : Patient     " << getPatient()->getId();
	cout << " begins blood Work." << endl;
}

