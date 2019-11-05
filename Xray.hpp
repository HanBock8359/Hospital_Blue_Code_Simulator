/**
 * Xray.hpp
 * PURPOSE: This file is subclass of Station
 */
#include "Station.hpp"

#ifndef XRAY_HPP_
#define XRAY_HPP_

class Xray : public Station{
	private:
		int workTime;
	public:
		Xray(int numXRayTech, int XRayTime);
		virtual ~Xray();

		void printQueue();

		int getWorkTime();		
		void print();
};

#endif /* XRAY_HPP_ */
