/**
 * PQueue.hpp
 * PURPOSE: This file is the subclass of Queue.cpp, a Priority Queue used for Patient objects
 */
#include "Queue.hpp"

#ifndef PQUEUE_HPP_
#define PQUEUE_HPP_

class PQueue : public Queue{
public:
	PQueue();
	virtual ~PQueue();

	void insert(ListItem* item);
	void print();
};

#endif /* PQUEUE_HPP_ */
