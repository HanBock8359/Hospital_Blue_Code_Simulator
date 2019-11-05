/**
 * Station.cpp
 * PURPOSE: This file is the abstract class to implement four different stations (Assessment, BloodWork, Xray, Treatment)
 */
#include "Station.hpp"

Station::Station() {
	this->numTech = 0;
	this->list = NULL;
	this->waitList = NULL;
	this->totalPatient = 0;
	this->totalActiveTime = 0;
	this->totalWaitTime = 0;
}

Station::Station(int numTech) {
	this->numTech = numTech;			//number of technician
	this->list = new Queue();			//Queue
	this->waitList = new PQueue();		//priority Queue
	this->totalPatient = 0;
	this->totalActiveTime = 0;
	this->totalWaitTime = 0;
}

Station::~Station() {
	// TODO Auto-generated destructor stub
}

int Station::getNumTech(){
	return numTech;
}
void Station::setNumTech(int numTech){
	this->numTech = numTech;
}

Queue* Station::getList(){
	return list;
}
void Station::setList(Queue* list){
	this->list = list;
}
PQueue* Station::getWaitList(){
	return waitList;
}
void Station::setWaitList(PQueue* waitList){
	this->waitList = waitList;
}
int Station::getTotalPatient(){
	return totalPatient;
}
void Station::addTotalPatient(int totalPatient){
	this->totalPatient += totalPatient;
}
int Station::getTotalActiveTime(){
	return totalActiveTime;
}
void Station::addTotalActiveTime(int totalActiveTime){
	this->totalActiveTime += totalActiveTime;
}
int Station::getTotalWaitTime(){
	return totalWaitTime;
}
void Station::addTotalWaitTime(int totalWaitTime){
	this->totalWaitTime += totalWaitTime;
}

void Station::enterStation(ListItem* item){
	list->insert(item);
	totalPatient++;
}

Patient* Station::exitStation(){
	return dynamic_cast<Patient*>(list->remove());
}

void Station::enterWaitList(ListItem* item){
	waitList->insert(item);
	cout << "Patient " << dynamic_cast<Patient*>(item)->getId() << " Queued in waitList!" << endl; 
}

Patient* Station::exitWaitList(){
	return dynamic_cast<Patient*>(waitList->remove());
}

void Station::print(){
	cout << "Please implement print method!" << endl;
}
