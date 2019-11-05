/**
 * Queue.hpp
 * PURPOSE: This file is the base class of data structure Queue
 */

#include "List.hpp"
#include "Node.hpp"

#ifndef QUEUE_HPP_
#define QUEUE_HPP_

class Queue : public List{
	private:
		Node* front;
		Node* end;
		int size;
	public:
		Queue();
		virtual ~Queue();

		void insert(ListItem* item);
		ListItem* remove();
		bool isEmpty();
		ListItem* top();
		bool search(ListItem* item);

		Node* getFront();
		void setFront(Node* front);
		Node* getEnd();
		void setEnd(Node* end);
		int getSize();
		void setSize(int size);

		void print();

};

#endif /* QUEUE_HPP_ */
