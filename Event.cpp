/**
 * Event.cpp
 * PURPOSE: This file is the abstract class to implement nine different events
 */
#include "Event.hpp"

Event::Event() {
	this->patient = NULL;
	this->time = 0;
}

//copy constructor
Event::Event(const Event& e){
	this->patient = new Patient(e.patient->getId(), e.patient->getAssessmentTime(), e.patient->getAssessmentTime(), 
								e.patient->getPriority(), e.patient->getDiagnostic(), e.patient->getTreatmentTime(),
								e.patient->getWaiting());
	this->time = e.time;
}

Event::Event(Patient* patient, int time) {
	this->patient = patient;
	this->time = time;
}

Event::~Event() {
	delete patient;
}

Patient* Event::getPatient(){
	return patient;
}

void Event::setPatient(Patient* patient){
	this->patient = patient;
}

int Event::getTime(){
	return time;
}

void Event::setTime(int time){
	this->time = time;
}

void Event::print(){
	cout << "Event!" << endl;
}

