/**
 * Assessment.cpp
 * PURPOSE: This file is subclass of Station
 */

#include "Assessment.hpp"

Assessment::Assessment(int numAssessmentNurses) : Station(numAssessmentNurses){
	this->waitLine = new Queue();
}

Assessment::~Assessment() {
	delete waitLine;
}

Queue* Assessment::getWaitLine(){
	return waitLine;
}

void Assessment::printQueue(){
	cout << "Assessment Station" << endl;
	getList()->print();
	getWaitLine()->print();
	cout << "Assessment Station" << endl;
}

void Assessment::enterStation(ListItem* item){
	getList()->insert(item);
	addTotalPatient(1);
}

Patient* Assessment::exitStation(){
	return dynamic_cast<Patient*>(getList()->remove());
}

void Assessment::enterWaitList(ListItem* item){
	waitLine->insert(item);
	cout << "Patient " << dynamic_cast<Patient*>(item)->getId() << " Queued in waitList!" << endl; 
}

Patient* Assessment::exitWaitList(){
	return dynamic_cast<Patient*>(waitLine->remove());
}

//this method prins the statistic of Assessment station
void Assessment::print(){
	cout << "Assessment   / Total Patients : " << getTotalPatient()
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
