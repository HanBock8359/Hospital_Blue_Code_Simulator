/**
 * PQueue.cpp
 * PURPOSE: This file is the subclass of Queue.cpp, a Priority Queue used for Patient objects
 */

#include "PQueue.hpp"

PQueue::PQueue() {
	// TODO Auto-generated constructor stub

}

PQueue::~PQueue() {
	// TODO Auto-generated destructor stub
}

//this method inserts the item into the Priority queue based on the priority and patient id
void PQueue::insert(ListItem* item){
	Node* temp = new Node();					//initialize the node
	temp->setItem(item);						//stores the new item
	temp->setNext(NULL);						//set next to null

	if(this->getFront() == NULL){				//if queue is empty
		setFront(temp);							//insert at front
		setEnd(temp);
	}
	else{
		Node* prev = NULL;						//previous Node ptr
		Node* curr = getFront();				//current Node ptr
		bool found = false;

		//finds the position where the item should be inserted at
		while(curr != NULL && found == false){
			//if priority is greater
			if( (dynamic_cast<Patient*>(temp->getItem())->getPriority()) < (dynamic_cast<Patient*>(curr->getItem())->getPriority())){
				found = true;
				break;
			}
			//if priority is same but id is lesser (arrived earlier)
			else if( (dynamic_cast<Patient*>(temp->getItem())->getPriority()) == (dynamic_cast<Patient*>(curr->getItem())->getPriority()) &&
					(dynamic_cast<Patient*>(temp->getItem())->getId() ) < (dynamic_cast<Patient*>(curr->getItem())->getId() ) ){
				found = true;
				break;
			}
			//if no conditions are met
			else{
				prev = curr;
				curr = curr->getNext();	//proceeds to next node
			}
		}

		//inserts the item into the queue
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

	setSize(getSize() + 1);										//increase the size of queue by 1
}

//this method prints the items in the queue
void PQueue::print(){
	cout << "-----Priority Queue!-----" << endl;
	
	Node* curr = getFront();
	while(curr != NULL){
		dynamic_cast<Patient*>(curr->getItem())->print();
		curr = curr->getNext();
	}

	cout << "-----End of Queue!-----" << endl;
}

