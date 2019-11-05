/*
 * PatientList.hpp
 *
 *  Created on: 2019. 2. 19.
 *      Author: kevin
 */

#include "Node.hpp"
#include "Patient.hpp"

#include <iostream>
using namespace std;

#ifndef PATIENTLIST_HPP_
#define PATIENTLIST_HPP_

class PatientList{
	private:
		Node* head;
	public:
		PatientList();
		virtual ~PatientList();

		void insert(Patient* p);
		bool search(Patient* p);
		bool remove(Patient* p);
};

#endif /* PATIENTLIST_HPP_ */
