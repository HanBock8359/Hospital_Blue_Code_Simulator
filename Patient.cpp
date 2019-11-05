/**
 * Patient.cpp
 * PURPOSE: This file is the subclass of ListItem
 */

#include "Patient.hpp"

//implementation
Patient::Patient(int id, int arrival, int assessmentTime, int priority, string diagnostic, int treatmentTime, bool waiting){
	this->id = id;
	this->arrival = arrival;
	this->assessmentTime = assessmentTime;
	this->priority = priority;
	this->diagnostic = diagnostic;

	if(diagnostic[0] == 'B'){
		this->bloodTest = true;
	}
	else{
		this->bloodTest = false;
	}

	if(diagnostic[1] == 'X'){
		this->xrayTest = true;
	}
	else{
		this->xrayTest = false;
	}

	this->treatmentTime = treatmentTime;
	this->waiting = waiting;
}

Patient::~Patient(){

}

int Patient::getId(){
	return id;
}

int Patient::getArrival(){
	return arrival;
}

int Patient::getAssessmentTime(){
	return assessmentTime;
}

int Patient::getPriority(){
	return priority;
}

string Patient::getDiagnostic(){
	return diagnostic;
}

bool Patient::getBloodTest(){
	return bloodTest;
}

bool Patient::getXrayTest(){
	return xrayTest;
}

void Patient::setBloodTest(bool b){
	this->bloodTest = b;
}

void Patient::setXrayTest(bool b){
	this->xrayTest = b;
}

int Patient::getTreatmentTime(){
	return treatmentTime;
}

bool Patient::getWaiting(){
	return waiting;
}

void Patient::setWaiting(bool waiting){
	this->waiting = waiting;
}

void Patient::print(){
	cout << id << " " << arrival << " " << assessmentTime << " " << priority << " " << bloodTest << " " << xrayTest << " " << treatmentTime << " " << endl;
}
