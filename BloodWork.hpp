/**
 * BloodWork.hpp
 * PURPOSE: This file is subclass of Station
 */

#include "Station.hpp"

#ifndef BLOODWORK_HPP_
#define BLOODWORK_HPP_

class BloodWork : public Station{
	private:
		int workTime;
	public:
		BloodWork(int numBloodTech, int bloodWorkTime);
		virtual ~BloodWork();
		
		void printQueue();
		
		int getWorkTime();
		void print();
};

#endif /* BLOODWORK_HPP_ */
