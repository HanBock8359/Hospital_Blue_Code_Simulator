/**
 * Treatment.cpp
 * PURPOSE: This file is subclass of Station
 */

#include "Treatment.hpp"

Treatment::Treatment(int numDoctors) : Station(numDoctors){
	// TODO Auto-generated constructor stub

}

Treatment::~Treatment() {
	// TODO Auto-generated destructor stub
}

void Treatment::printQueue(){
	cout << "Treatment Station" << endl;
	getList()->print();
	getWaitList()->print();
	cout << "Treatment Station" << endl;
}

//this method prints the statistic of Treatment station
void Treatment::print(){
	cout << "Treatment    / Total Patients : " << getTotalPatient()
			<< " / Total service time : " << getTotalActiveTime()
			<< " / Average service time " << (float)getTotalActiveTime() / (float)getTotalPatient()
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
