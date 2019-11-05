/**
 * BloodWork.cpp
 * PURPOSE: This file is subclass of Station
 */

#include "BloodWork.hpp"

//constructor
BloodWork::BloodWork(int numBloodTech, int bloodWorkTime) : Station(numBloodTech){
	this->workTime = bloodWorkTime;
}

BloodWork::~BloodWork() {
	// TODO Auto-generated destructor stub
}

//get method
int BloodWork::getWorkTime(){
	return workTime;
}

void BloodWork::printQueue(){
	cout << "BloodWork Station" << endl;
	getList()->print();
	getWaitList()->print();
	cout << "BloodWork Station" << endl;
}

//this method prints the statistic of BloodWork station
void BloodWork::print(){
	cout << "BloodWork    / Total Patients : " << getTotalPatient()
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
