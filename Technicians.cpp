/*
 * Technicians.cpp
 *
 *  Created on: 2019. 2. 25.
 *      Author: kevin
 */

#include "Technicians.hpp"

Technicians::Technicians() {
	busy = false;
	list = new PQueue();
}

Technicians::~Technicians() {
	// TODO Auto-generated destructor stub
}

bool Technicians::getBusy(){
	return busy;
}

void Technicians::setBusy(bool busy){
	this->busy = busy;
}

PQueue* Technicians::getList(){
	return list;
}

void Technicians::setList(PQueue* list){
	this->list = list;
}
