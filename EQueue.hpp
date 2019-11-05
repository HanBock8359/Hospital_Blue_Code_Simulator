/**
 * EQueue.hpp
 * PURPOSE: This file is the subclass of Queue.cpp, a Priority Queue used for Event objects
 */

#include "Queue.hpp"

#ifndef EQUEUE_HPP_
#define EQUEUE_HPP_

class EQueue : public Queue{
public:
	EQueue();
	virtual ~EQueue();

	void insert(ListItem* item);
	void print();
};

#endif /* EQUEUE_HPP_ */
