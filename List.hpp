/*
 * List.hpp
 */

#ifndef LIST_HPP_
#define LIST_HPP_

#include "Patient.hpp"
#include "Event.hpp"

class List {
public:
	List();
	virtual ~List();

	virtual void insert(ListItem* item);
	virtual ListItem* remove();
	virtual bool isEmpty();
	virtual ListItem* top();

	virtual void print() = 0;
};

#endif /* LIST_HPP_ */
