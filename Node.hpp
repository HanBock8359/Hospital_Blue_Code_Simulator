/**
 * Node.hpp
 * PURPOSE: This file is the Generic data structure Node, stores the Listitem and used for Linked list and Queue
 */
#include "ListItem.hpp"

#include <iostream>
using namespace std;

#ifndef NODE_HPP_
#define NODE_HPP_

class Node{
	private:
		ListItem* item;
		Node* next;
	public:
		Node();
		Node(ListItem* item, Node* next);
		virtual ~Node();

		ListItem* getItem();
		void setItem(ListItem* item);
		Node* getNext();
		void setNext(Node* next);
};

#endif /* NODE_HPP_ */
