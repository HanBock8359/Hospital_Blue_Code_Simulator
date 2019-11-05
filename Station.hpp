/**
 * Station.hpp
 * PURPOSE: This file is the abstract class to implement four different stations (Assessment, BloodWork, Xray, Treatment)
 */
#include "Technicians.hpp"
#include "PQueue.hpp"
#include <iostream>
using namespace std;

#ifndef Station_HPP_
#define Station_HPP_

class Station {
	private:
		int numTech;
		Queue* list;
		PQueue* waitList;
		int totalPatient;
		int totalActiveTime;
		int totalWaitTime;
	public:
		Station();
		Station(int numTech);
		virtual ~Station();

		int getNumTech();
		void setNumTech(int numTech);
		Queue* getList();
		void setList(Queue* list);
		PQueue* getWaitList();
		void setWaitList(PQueue* waitList);
		int getTotalPatient();
		void addTotalPatient(int totalPatient);
		int getTotalActiveTime();
		void addTotalActiveTime(int totalActiveTime);
		int getTotalWaitTime();
		void addTotalWaitTime(int totalWaitTime);
		
		void enterStation(ListItem* item);
		Patient* exitStation();
		void enterWaitList(ListItem* item);
		Patient* exitWaitList();
		
		virtual void print() = 0;
};

#endif /* Station_HPP_ */
