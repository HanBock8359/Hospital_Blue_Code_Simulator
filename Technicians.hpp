/*
 * Technicians.hpp
 *
 *  Created on: 2019. 2. 25.
 *      Author: kevin
 */

#include "PQueue.hpp"
#include <iostream>
#include <string>

#ifndef TECHNICIANS_HPP_
#define TECHNICIANS_HPP_

class Technicians {
private:
	bool busy;
	PQueue* list;
public:
	Technicians();
	virtual ~Technicians();

	bool getBusy();
	void setBusy(bool busy);
	PQueue* getList();
	void setList(PQueue* list);
};

#endif /* TECHNICIANS_HPP_ */
