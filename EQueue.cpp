/**
 * EQueue.cpp 
 * PURPOSE: This file is the subclass of Queue.cpp, a Priority Queue used for Event objects
 */


#include "EQueue.hpp"

EQueue::EQueue() {
	// TODO Auto-generated constructor stub

}

EQueue::~EQueue() {
	// TODO Auto-generated destructor stub
}

//this method inserts the item into the Priority queue based on the time, patient id, then priority
void EQueue::insert(ListItem* item){
	Node* temp = new Node();				//initialize the node
	temp->setItem(item);					//stores the new item
	temp->setNext(NULL);					//set next to null

	if(this->getFront() == NULL){			//if queue is empty
		setFront(temp);						//insert at front
		setEnd(temp);
	}
	else{
		Node* prev = NULL;					//previous Node ptr
		Node* curr = getFront();			//current Node ptr
		bool found = false;

		//finds the position where should the new item be inserted at
		while(curr != NULL && found == false){
			//if time is greater
			if( (dynamic_cast<Event*>(temp->getItem())->getTime()) < (dynamic_cast<Event*>(curr->getItem())->getTime())){
				found = true;
				break;
			}
			//if time is identical and Priority is higher
			else if((dynamic_cast<Event*>(temp->getItem())->getTime()) == (dynamic_cast<Event*>(curr->getItem())->getTime()) &&
					(dynamic_cast<Event*>(temp->getItem())->getPatient()->getPriority() ) < (dynamic_cast<Event*>(curr->getItem())->getPatient()->getPriority() ) ){
				found = true;
				break;
			}
			//if time is identical and id is lesser (arrived earlier) and priority greater
			else if( (dynamic_cast<Event*>(temp->getItem())->getTime()) == (dynamic_cast<Event*>(curr->getItem())->getTime()) &&
					 (dynamic_cast<Event*>(temp->getItem())->getPatient()->getId() ) < (dynamic_cast<Event*>(curr->getItem())->getPatient()->getId() ) &&
					 (dynamic_cast<Event*>(temp->getItem())->getPatient()->getPriority() ) == (dynamic_cast<Event*>(curr->getItem())->getPatient()->getPriority() ) ){
				found = true;
				break;
			}
			else{
				prev = curr;
				curr = curr->getNext();	//proceeds to next node
			}
		}

		//insert the item into the queue
		if(found){												//if found the position
			if(curr->getItem() == getFront()->getItem()){		//if inserting at head
				temp->setNext(curr);
				setFront(temp);
			}
			else{												//if inserting at middle
				temp->setNext(curr);
				prev->setNext(temp);
			}
		}
		else{													//if inserting at end
			prev->setNext(temp);
			setEnd(temp);
		}
	}

	setSize(getSize() + 1);				//increases the size by 1
}

//this method prints the items in the queue
void EQueue::print(){
	cout << "-----Event Queue!-----" << endl;
	
	Node* curr = getFront();
	while(curr != NULL){
		dynamic_cast<Event*>(curr->getItem())->print();
		curr = curr->getNext();
	}

	cout << "-----End of Queue!-----" << endl;
}
