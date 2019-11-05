/*
 * PatientList.cpp
 *
 *  Created on: 2019. 2. 19.
 *      Author: kevin
 */

#include "PatientList.hpp"

PatientList::PatientList(){
	head = NULL;
}

PatientList::~PatientList(){
	head = NULL;
}

void PatientList::insert(Patient* p){
	if(head == NULL){
		Node* newP = new Node(p, NULL);
		head = newP;
	}
	else{	//insert at tail
		Node* newP = new Node(p, head);
		head = newP;
	}
}

bool PatientList::search(Patient* p){
	bool search = false;
	Node* curr = head;

	while(curr != NULL){
		if(p == dynamic_cast<Patient*>(curr->getItem())){
			search = true;	//
			break;			//stops the loop
		}
		curr = curr->getNext();	//proceeds to next node
	}

	return search;
}

bool PatientList::remove(Patient* p){
	bool remove = false;
	Node* curr = head;

	while(curr != NULL){
		if(p == dynamic_cast<Patient*>(curr->getItem())){
			remove = true;	//
			break;			//stops the loop
		}
		curr = curr->getNext();	//proceeds to next node
	}

	return remove;
}


