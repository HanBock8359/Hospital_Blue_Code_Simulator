/**
 * Hospital.cpp
 * PURPOSE: This file is to simulate the Discrete Event Simulation
 */
#include "Hospital.hpp"

static int patientNumber = 1;

Hospital::Hospital(){
	this->assessment = NULL;
	this->bloodwork = NULL;
	this->xray = NULL;
	this->treatment = NULL;
	this->history = NULL;
}

//constructor
Hospital::Hospital(int numAssessmentNurses, int numBloodTech, int numXRayTech, int numDoctors, int bloodWorkTime, int XRayTime) {
	this->assessment = new Assessment(numAssessmentNurses);
	this->bloodwork = new BloodWork(numBloodTech, bloodWorkTime);
	this->xray = new Xray(numXRayTech, XRayTime);
	this->treatment = new Treatment(numDoctors);
	this->history = new EQueue();
}

Hospital::~Hospital() {
	// TODO Auto-generated destructor stub
}

//----get methods & set methods----
Assessment* Hospital::getAssessment(){
	return assessment;
}
void Hospital::setAssessment(Assessment* assessment){
	this->assessment = assessment;
}
BloodWork* Hospital::getBloodWork(){
	return bloodwork;
}
void Hospital::setBloodWork(BloodWork* bloodwork){
	this->bloodwork = bloodwork;
}
Xray* Hospital::getXray(){
	return xray;
}
void Hospital::setXray(Xray* xray){
	this->xray = xray;
}
Treatment* Hospital::getTreatment(){
	return treatment;
}
void Hospital::setTreatment(Treatment* treatment){
	this->treatment = treatment;
}
//----get methods & set methods----

//this method provides the simulation for Assignment 2
void Hospital::simulate(string fileName){
	ifstream* inFile = new ifstream;
//	string fileName;
	string line;
//	cout << "Enter the name of text file: ";
//	getline(cin, fileName);										//receives the user input
	inFile->open(fileName.c_str());								//opens the file

	if(!inFile->is_open()){										//if text file could not be found,
		cout << "Unable to open the file." << endl;
	}
	else{														//if found the text file,
//		Queue* waitList = new Queue();							//patient list waiting for assessment
		EQueue* eventList = new EQueue();						//event list
		
		//FIRST arrival
		getline(*inFile, line);									//reads the line from text file
		
		while(isComment(line)){									//if comment is read
			getline(*inFile, line);								//reads another line from text file
		}
		
		processArrival(eventList, line);				//processes arrival

		//SECOND or MORE arrival
		while(!eventList->isEmpty()){							//while Event is present in the event list
			eventList->print();		//test
			
			ListItem* temp = eventList->remove();				//remove that event from the queue

			if(dynamic_cast<Arrival*>(temp)){					//if ARRIVAL event is found
				if(getline(*inFile, line)){						//if line of patient information is read,
				
					while(isComment(line)){						//if comment is read
						getline(*inFile, line);					//reads another line from text file
					}
					
					processArrival(eventList, line);	//insert another arrival event
				}
				history->insert(new Arrival(*(dynamic_cast<Arrival*>(temp))));	//copies the event (deep copy using copy constructor));
			}
			else if(dynamic_cast<StartAssessment*>(temp)){		//if STARTASSESSMENT Event is found
				processStartAssessment(							//processess STARTASSESSMENT Event
				eventList, dynamic_cast<StartAssessment*>(temp));
				
				history->insert(new StartAssessment(*(dynamic_cast<StartAssessment*>(temp))));	//copies the event (deep copy using copy constructor));
			}
			else if(dynamic_cast<CompleteAssessment*>(temp)){	//if COMPLETEASSESSMENT Event is found
				processCompleteAssessment(						//processess COMPLETEASSESSMENT Event
				eventList, dynamic_cast<CompleteAssessment*>(temp));
				
				history->insert(new CompleteAssessment(*(dynamic_cast<CompleteAssessment*>(temp))));	//copies the event (deep copy using copy constructor));
			}
			else if(dynamic_cast<StartBloodWork*>(temp)){		//if STARTBLOODWORK Event is found
				processStartBloodWork(							//processess STARTBLOODWORK Event
				eventList, dynamic_cast<StartBloodWork*>(temp));
				
				history->insert(new StartBloodWork(*(dynamic_cast<StartBloodWork*>(temp))));	//copies the event (deep copy using copy constructor));
			}
			else if(dynamic_cast<CompleteBloodWork*>(temp)){	//if COMPLETEBLOODWORK Event is found
				processCompleteBloodWork(						//processess COMPLETEBLOODWORK Event
				eventList, dynamic_cast<CompleteBloodWork*>(temp));
				
				history->insert(new CompleteBloodWork(*(dynamic_cast<CompleteBloodWork*>(temp))));	//copies the event (deep copy using copy constructor));
			}
			else if(dynamic_cast<StartXray*>(temp)){			//if STARTXRAY Event is found
				processStartXray(								//processess STARTXRAY Event
				eventList, dynamic_cast<StartXray*>(temp));
				
				history->insert(new StartXray(*(dynamic_cast<StartXray*>(temp))));	//copies the event (deep copy using copy constructor));
			}
			else if(dynamic_cast<CompleteXray*>(temp)){			//if COMPLETEXRAY Event is found
				processCompleteXray(							//processess COMPLETEXRAY Event
				eventList, dynamic_cast<CompleteXray*>(temp));
				
				history->insert(new CompleteXray(*(dynamic_cast<CompleteXray*>(temp))));	//copies the event (deep copy using copy constructor));
			}
			else if(dynamic_cast<StartTreatment*>(temp)){		//if STARTTREATMENT Event is found
				processStartTreatment(							//processess STARTTREATMENT Event
				eventList, dynamic_cast<StartTreatment*>(temp));
				
				history->insert(new StartTreatment(*(dynamic_cast<StartTreatment*>(temp))));	//copies the event (deep copy using copy constructor));
			}
			else if(dynamic_cast<Discharge*>(temp)){			//if DISCHARGE Event is found
				processDischarge(								//processess DISCHARGE Event
				eventList, dynamic_cast<Discharge*>(temp));
				
				history->insert(new Discharge(*(dynamic_cast<Discharge*>(temp))));	//copies the event (deep copy using copy constructor));
			}
			else{												//if Event pointer is not found,
				cout << "Wrong Event (Item) is in the list!" << endl;
			}
		}

	}
	
	history->print();											//prints the history of events
	inFile->close(); 											//closes the file
}

//this method prints the statistics of 4 stations
void Hospital::statistics(){
	assessment->print();
	bloodwork->print();
	xray->print();
	treatment->print();
}

//this method checks if current line contatins comment (stating with '#')
bool Hospital::isComment(string line){
	if(line[0] == '#'){			//if symbol # is read
		cout << line << endl;	//prints the line
		return true;			//returns true
	}
	else{						//if line is not comment
		return false;			//returns false
	}
}

//this method processes Arrival Event
void Hospital::processArrival(EQueue* eventList, string line){
		istringstream *iss = new istringstream(line);
		string stuff;
	
		int arrival, assessmentTime, priority, treatmentTime;
		string diagnostic;
		Patient* newPatient;
		Event* newEvent;
	
		*iss >> arrival;										//reads arrival
		*iss >> assessmentTime;									//reads assessment time
		*iss >> priority;										//reads priority
		*iss >> diagnostic;										//reads diagnostic (string)
		*iss >> treatmentTime;									//reads treatment time
	
		newPatient = new Patient(								//create a new patient object
		patientNumber, arrival, assessmentTime, priority, diagnostic, treatmentTime, false);	
		
		patientNumber++;										//increase patient number (static)

		newEvent = new Arrival(newPatient, arrival);			//creates a new arrival event
		eventList->insert(newEvent);							//insert the event to the event list
	
		if(assessment->getList()->getSize() < assessment->getNumTech()){ //if getting service right away
			assessment->enterStation(newPatient);				//patient will meet technician
			newEvent = new StartAssessment(newPatient, arrival);//
			eventList->insert(newEvent);						//insert StartAssessment event
		}
		else{													//if needs to be queued
			newPatient->setWaiting(true);						//patient is now waiting
			assessment->enterWaitList(newPatient);				//insert new patient to the waitlist of Assessment
		}
		
		assessment->printQueue();
}

//this method processes StartAssessment Event
void Hospital::processStartAssessment(EQueue* eventList, Event* e){
	Patient* newPatient = e->getPatient();											//retrieve patient information from the Event
	Event* newEvent = new CompleteAssessment(newPatient, e->getTime() + newPatient->getAssessmentTime());	//retrieve event information
	assessment->addTotalActiveTime(newPatient->getAssessmentTime());				//increase service time
	eventList->insert(newEvent);													//insert event to event list
	
	assessment->printQueue();
}

//this method processes CompleteAssessment Event
void Hospital::processCompleteAssessment(EQueue* eventList, Event* e){
	assessment->exitStation();														//remove a patient from the list

	Patient* newPatient = e->getPatient();											//patient at this event
	newPatient->setWaiting(false);													//patient is not waiting
	Event* newEvent;
	
	//if there is a patient in waitlist in assessment
	if(!assessment->getWaitLine()->isEmpty()){
		Patient* tempPatient = assessment->exitWaitList();							//remove patient in a waitlist
		tempPatient->setWaiting(false);												//patient is now waiting
		assessment->enterStation(tempPatient);										//insert patient to the list and gets an assessment
		
		if(e->getTime() > tempPatient->getArrival()){								//if current time is greater than a patient's arrival (the patient had to wait)
			assessment->addTotalWaitTime(e->getTime() - tempPatient->getArrival());	//increase total wait time
		}
		
		Event* tempEvent;
		
		if(e->getTime() < tempPatient->getArrival()){								//if current time is lesser than patient's arrival
			tempEvent = new StartAssessment(tempPatient, tempPatient->getArrival());//event starts at patient's arrival time
		}
		else{																		//if otherwise,
			tempEvent = new StartAssessment(tempPatient, e->getTime());				//event starts at current time
		}
		
		eventList->insert(tempEvent);												//insert StartAssessment event to event list
	}
	
	//check what tests need to be done for the patient that just finished the assessment
	if(newPatient->getBloodTest() && newPatient->getXrayTest()){			//needs BloodTest AND XrayTest	
		if(bloodwork->getList()->getSize() < bloodwork->getNumTech()){		//if BloodWork has available technicians
			newEvent = new StartBloodWork(newPatient, e->getTime());		//create StartBloodWork event
			bloodwork->enterStation(newPatient);							//insert patient to BloodTest 
		}
		else if(xray->getList()->getSize() < xray->getNumTech()){			//if Xray has available technicians	
			newEvent = new StartXray(newPatient, e->getTime());				//create StartXray event
			xray->enterStation(newPatient);									//insert patient to Xray
		}
		else{																//if no technicians are available
			int i = rand() % 2;												//choose a random number (0 to 1)
			
			if(i == 0){														//if 0 is selected (bloodwork)
				newPatient->setWaiting(true);								//set wait balue to be true (indicates that patient is waiting)
				bloodwork->enterWaitList(newPatient);						//queue the patient to the bloodwork
			}																
			else{															//if 1 is selected (xray)
				newPatient->setWaiting(true);								//set wait value to be true (indicates that patient is waiting)
				xray->enterWaitList(newPatient);							//queue the patient to the xray						
			}
		}
	}
	else if(newPatient->getBloodTest() || newPatient->getXrayTest()){		//needs BloodTest OR XrayTest
	
		//if the patient should go to blood test
		if(newPatient->getBloodTest()){
			if(bloodwork->getList()->getSize() < bloodwork->getNumTech()){	//if BloodWork has available technicians
				newEvent = new StartBloodWork(newPatient, e->getTime());	//create StartBloodWork event
				bloodwork->enterStation(newPatient);						//insert patient to BloodTest 
			}
			else{															//if no technicians are available
				newPatient->setWaiting(true);								//set wait balue to be true (indicates that patient is waiting)
				bloodwork->enterWaitList(newPatient);						//queue the patient to the bloodwork
			}
		}
		//if the patient should go to xray test
		else if(newPatient->getXrayTest()){
			if(xray->getList()->getSize() < xray->getNumTech()){			//if Xray has available technicians
				newEvent = new StartXray(newPatient, e->getTime());			//create StartXray event
				xray->enterStation(newPatient);								//insert patient to Xray
			}
			else{															//if no technicians are available
				newPatient->setWaiting(true);								//set wait value to be true (indicates that patient is waiting)
				xray->enterWaitList(newPatient);							//queue the patient to the xray						
			}
		}
	}
	//needs Treatment right away
	else{																	
		if(treatment->getList()->getSize() < treatment->getNumTech()){		//if Treatment has available technicians
			newEvent = new StartTreatment(newPatient, e->getTime());		//create StartTreatment event
			treatment->enterStation(newPatient);							//insert patient to Treatment
		}
		else{																//if no technicians are available
			newPatient->setWaiting(true);									//set wait value to be true (indicates that patient is waiting)
			treatment->enterWaitList(newPatient);							//queue the patient to the treatment
		}
	}
	
	eventList->insert(newEvent);
	
	assessment->printQueue();
	bloodwork->printQueue();
	xray->printQueue();
	treatment->printQueue();
}

//this method processes StartBloodWork Event
void Hospital::processStartBloodWork(EQueue* eventList, Event* e){
	Patient* newPatient = e->getPatient();												//patient at this event
//	newPatient->setWaiting(false);
	
	Event* newEvent = new CompleteBloodWork(newPatient, e->getTime() + bloodwork->getWorkTime());
	eventList->insert(newEvent);														//inserts event
	
	bloodwork->printQueue();
}

//this method processes StartXray Event
void Hospital::processStartXray(EQueue* eventList, Event* e){
	Patient* newPatient = e->getPatient();												//patient at this event
//	newPatient->setWaiting(false);

	Event* newEvent = new CompleteXray(newPatient, e->getTime() + xray->getWorkTime());
	eventList->insert(newEvent);														//inserts event
	
	xray->printQueue();
}

//this method processes CompleteBloodWork Event
void Hospital::processCompleteBloodWork(EQueue* eventList, Event* e){
	bloodwork->exitStation();															//remove a patient from the list

	Patient* newPatient = e->getPatient();												//patient at this event
	newPatient->setBloodTest(false);
																						//bloodTest is false, no need to check for blood test
	Event* newEvent;
	
	//if there is a patient in waitlist in bloodwork
	if(!bloodwork->getWaitList()->isEmpty()){
		Patient* tempPatient = bloodwork->exitWaitList();								//remove patient in a waitlist
		tempPatient->setWaiting(false);
		bloodwork->enterStation(tempPatient);											//insert patient to the list and gets an assessment
		bloodwork->addTotalWaitTime(e->getTime());										//increase total active time
	
		Event* tempEvent = new StartBloodWork(tempPatient, e->getTime());
		eventList->insert(tempEvent);
	}

	if(newPatient->getXrayTest()){														//if xray should also be done,
		if(xray->getList()->getSize() < xray->getNumTech()){							//if technicians are available
			newEvent = new StartXray(newPatient, e->getTime());							//new StartXray event
			xray->enterStation(newPatient);												//insert patient to Xray station
			eventList->insert(newEvent);												//insert event to the event list
		}
		else{																			//if needs to be placed in wait list
			newPatient->setWaiting(true);												//the patient is now waiting
			xray->enterWaitList(newPatient);											//insert the patient to wait list
		}
	}
	else{																				//if all test are done
		if(treatment->getList()->getSize() < treatment->getNumTech()){					//if technicians are available
			newEvent = new StartTreatment(newPatient, e->getTime());					//new StartTreatment event
			treatment->enterStation(newPatient);										//insert patient to Treatment station
			eventList->insert(newEvent);												//insert event to the event list
		}
		else{																			//if needs to be placed in wait list
			newPatient->setWaiting(true);
			treatment->enterWaitList(newPatient);
		}
	}
	
	bloodwork->printQueue();
}

//this method processes CompleteXray Event
void Hospital::processCompleteXray(EQueue* eventList, Event* e){
	xray->exitStation();														//remove a patient from the list

	Patient* newPatient = e->getPatient();										//patient at this event
	newPatient->setXrayTest(false);												//xrayTest is false
	Event* newEvent;
	
	//if there is a patient in waitlist in xray
	if(!xray->getWaitList()->isEmpty()){
		Patient* tempPatient = xray->exitWaitList();							//remove patient in a waitlist
		tempPatient->setWaiting(false);
		xray->enterStation(tempPatient);										//insert patient to the list and gets an assessment
		xray->addTotalWaitTime(e->getTime() - tempPatient->getArrival());		//increase total active time
		
		Event* tempEvent = new StartXray(tempPatient, e->getTime());			//new StartXray event
		eventList->insert(tempEvent);											//insert event to the event list
	}

	if(newPatient->getBloodTest()){												//if xray should also be done,
		if(bloodwork->getList()->getSize() < xray->getNumTech()){				//if technicians are available
			newEvent = new StartXray(newPatient, e->getTime());					//new StartXray event
			bloodwork->enterStation(newPatient);								//insert the patient to Bloodwork
			eventList->insert(newEvent);										//insert event to the event list
		}
		else{																	//if no technicians are available
			newPatient->setWaiting(true);										//the patient is now waiting
			bloodwork->enterWaitList(newPatient);								//insert the patient to wait list
		}
	}
	else{																		//if all test are done
		if(treatment->getList()->getSize() < treatment->getNumTech()){			//if technicians are available
			newEvent = new StartTreatment(newPatient, e->getTime());			//new StartTreatment Event
			treatment->enterStation(newPatient);								//insert the patient to Treatment
			eventList->insert(newEvent);										//insert event to the event list
		}
		else{																	//if no technicians are available
			newPatient->setWaiting(true);										//the patient is now waiting
			treatment->enterWaitList(newPatient);								//insert the patient to wait list
		}
	}
	
	xray->printQueue();
}

//this method processes StartTreatment Event
void Hospital::processStartTreatment(EQueue* eventList, Event* e){
	Patient* newPatient = e->getPatient();											//patient at this event

	Event* newEvent = new Discharge(newPatient, e->getTime() + newPatient->getTreatmentTime());
	treatment->addTotalActiveTime(newPatient->getTreatmentTime());					//calculates total active time of Treatment 
	eventList->insert(newEvent);													//inserts event
	
	treatment->printQueue();
}

//this method processes Discharge Event
void Hospital::processDischarge(EQueue* eventList, Event* e){
	treatment->exitStation();														//remove a patient from the list
	
	Patient* newPatient = e->getPatient();
	
	//if there is a patient in waitlist in treatment
	if(!treatment->getWaitList()->isEmpty()){
		Patient* tempPatient = treatment->exitWaitList();							//remove patient in a waitlist
		tempPatient->setWaiting(false);
		treatment->enterStation(tempPatient);										//insert patient to the list and gets an assessment
		treatment->addTotalWaitTime(e->getTime() - tempPatient->getArrival());		//increase total wait time
		
		Event* tempEvent = new StartTreatment(tempPatient, e->getTime());			
		eventList->insert(tempEvent);												//insert a new StartTreatment event
	}
	
	treatment->printQueue();
}

