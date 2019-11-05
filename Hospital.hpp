/**
 * Hospital.hpp
 * PURPOSE: This file is to simulate the Discrete Event Simulation
 */
#include "Arrival.hpp"
#include "StartAssessment.hpp"
#include "CompleteAssessment.hpp"
#include "StartBloodWork.hpp"
#include "StartXray.hpp"
#include "StartTreatment.hpp"
#include "CompleteBloodWork.hpp"
#include "CompleteXray.hpp"
#include "Discharge.hpp"

#include "Assessment.hpp"
#include "BloodWork.hpp"
#include "Xray.hpp"
#include "Treatment.hpp"

#include "PQueue.hpp"
#include "EQueue.hpp"
#include "PatientList.hpp"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
using namespace std;

#ifndef HOSPITAL_HPP_
#define HOSPITAL_HPP_

class Hospital {
	private:
		Assessment* assessment;
		BloodWork* bloodwork;
		Xray* xray;
		Treatment* treatment;
		EQueue* history;
	public:
		Hospital();
		Hospital(int numAssessmentNurses, int numBloodTech, int numXRayTech, int numDoctors, int bloodWorkTime, int XRayTime);
		virtual ~Hospital();

		Assessment* getAssessment();
		void setAssessment(Assessment* assessment);
		BloodWork* getBloodWork();
		void setBloodWork(BloodWork* bloodwork);
		Xray* getXray();
		void setXray(Xray* xray);
		Treatment* getTreatment();
		void setTreatment(Treatment* treatment);

		void simulate(string fileName);
		void statistics();
	
		bool isComment(string line);
		void processArrival(EQueue* eventList, string line);
		void processStartAssessment(EQueue* eventList, Event* e);
		void processCompleteAssessment(EQueue* eventList, Event* e);
		void processStartBloodWork(EQueue* eventList, Event* e);
		void processStartXray(EQueue* eventList, Event* e);
		void processCompleteBloodWork(EQueue* eventList, Event* e);
		void processCompleteXray(EQueue* eventList, Event* e);
		void processStartTreatment(EQueue* eventList, Event* e);
		void processDischarge(EQueue* eventList, Event* e);
};

#endif /* HOSPITAL_HPP_ */
