/**
 * ListItem.hpp
 * PURPOSE: This file is the abstract class to implement generic data structure that can be used in Linked list, Queue and Priority Queue
 */

#ifndef LISTITEM_HPP_
#define LISTITEM_HPP_

#include <iostream>
using namespace std;

class ListItem {
public:
	ListItem();
	virtual ~ListItem();
	virtual void print() = 0;
};

#endif /* LISTITEM_HPP_ */
