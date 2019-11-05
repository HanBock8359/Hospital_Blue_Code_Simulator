/**
 * Xray.cpp
 * PURPOSE: This file is subclass of Station
 */
#include "Xray.hpp"

Xray::Xray(int numXRayTech, int XRayTime) : Station(numXRayTech){
	this->workTime = XRayTime;
}

Xray::~Xray() {
	// TODO Auto-generated destructor stub
}

void Xray::printQueue(){
	cout << "Xray Station" << endl;
	getList()->print();
	getWaitList()->print();
	cout << "Xray Station" << endl;
}

int Xray::getWorkTime(){
	return workTime;
}

//this method prints the statistic of Xray station
void Xray::print(){
	cout << "Xray         / Total Patients : " << getTotalPatient()
			<< " / Total service time : " << getWorkTime() * getTotalPatient()
			<< " / Average service time " << (float)(getWorkTime())
			<< " / Total wait time : " << getTotalWaitTime()
			<< " / Average wait time " << (float)getTotalWaitTime() / (float)getTotalPatient()
			<< endl;
}

/*

			    Total        Service Time          Wait Time
   Station     patients    Total   Average      Total   Average
----------------------------------------------------------------
Assessment       1          22        22         0         0
Blood Work       1          15        15         0         0
X-ray            1          25        25         0         0
Treatment        1          39        39         0         0
*/
