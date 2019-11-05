/**
 * Queue.cpp
 * PURPOSE: This file is the base class of data structure Queue
 */

#include "Queue.hpp"

Queue::Queue() {
	this->front = NULL;
	this->end = NULL;
	this->size = 0;
}

Queue::~Queue() {
	// TODO Auto-generated destructor stub
}

//this method inserts an item into the queue
void Queue::insert(ListItem* item){
	Node* temp = new Node();				//node that will store the new item
	temp->setItem(item);					//initialize item with given item
	temp->setNext(NULL);					//initialize next to NULL

	if(front == NULL){						//if front is null
		front = end = temp;					//both front and end will be the first item
	}
	else{									//if at least one item exists,
		end->setNext(temp);					//inserts at the end
		end = temp;							//set the new item as the end
	}

	size++;									//increases the size
}

//this method removes the front item in the queue
ListItem* Queue::remove(){
	ListItem* tempItem = NULL;				//this will store the result

	if(size > 0){							//if there exists at least one item,
		tempItem = front->getItem();		//store the front item in the queue

		if(front == end){					//if both front and end are same (only one item)
			front = end = NULL;				//sets both front and end to NULL
		}
		else{								//if more than 2 items are present,
			front = front->getNext();		//front item will be deleted
		}

		size--;								//decreases the size by 1
	}

	return tempItem;						//return NULL if not deleted, returns corressponding ListItem if deleted
}

//this method checks if the queue is emtpy
bool Queue::isEmpty(){
	if(front == NULL && end == NULL){	//if the queue is empty,
		return true;					//returns true
	}
	else{								//if the queue is not empty
		return false;					//returns false
	}
}

//this method returns the item in front of queue
ListItem* Queue::top(){
	return front->getItem();			//returns the top item
}

//this method searchs if the given item exists in the queue
bool Queue::search(ListItem* item){
	bool found = false;
	Node* curr = getFront();			//starts from the top

	//searchs the queue
	while(curr != NULL && found == false){
		if(curr->getItem() == item){	//if found the same item,
			found = true;				//stops the loop
		}
		curr = curr->getNext();			//proceeds to the next node
	}

	return found;						//returns true if found, false otherwise
}

//----get and set methods----
Node* Queue::getFront(){
	return front;
}

void Queue::setFront(Node* front){
	this->front = front;
}

Node* Queue::getEnd(){
	return end;
}

void Queue::setEnd(Node* end){
	this->end = end;
}

int Queue::getSize(){
	return size;
}

void Queue::setSize(int size){
	this->size = size;
}
//----get and set methods----

//this method prints the items in the queue
void Queue::print(){
	cout << "-----Queue!-----" << endl;
	
	Node* curr = front;
	while(curr != NULL){
		dynamic_cast<Patient*>(curr->getItem())->print();
		curr = curr->getNext();
	}

	cout << "-----End of Queue!-----" << endl;
}



