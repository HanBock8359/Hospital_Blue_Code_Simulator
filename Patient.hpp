/**
 * Patient.hpp
 * PURPOSE: This file is the subclass of ListItem
 */

#include "ListItem.hpp"
#include <iostream>
#include <string>
using namespace std;

#ifndef PATIENT_HPP_
#define PATIENT_HPP_

//interface
class Patient : public ListItem{
	private:
		int id;
		//below five values to be assigned by txt.file
		int arrival;
		int assessmentTime;
		int priority;
		string diagnostic;
		bool bloodTest;
		bool xrayTest;
		int treatmentTime;
		bool waiting;
	public:
		Patient(int id, int arrival, int assessmentTime, int priority, string diagnostic, int treatmentTime, bool waiting);
		virtual ~Patient();

		int getId();
		int getArrival();
		int getAssessmentTime();
		int getPriority();
		string getDiagnostic();
		bool getBloodTest();
		void setBloodTest(bool b);
		bool getXrayTest();
		void setXrayTest(bool b);
		int getTreatmentTime();
		
		bool getWaiting();
		void setWaiting(bool waiting);

		void print();
};


#endif /* PATIENT_HPP_ */
