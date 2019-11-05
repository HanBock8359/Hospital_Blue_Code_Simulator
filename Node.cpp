/**
 * Node.cpp 
 * PURPOSE: This file is the Generic data structure Node, stores the Listitem and used for Linked list and Queue
 */
#include "Node.hpp"

Node::Node() {
	this->item = NULL;
	this->next = NULL;
}

Node::Node(ListItem* item, Node *next) {
	this->item = item;
	this->next = next;
}

Node::~Node() {

}

ListItem* Node::getItem(){
	return item;
}

void Node::setItem(ListItem* item){
	this->item = item;
}

Node* Node::getNext(){
	return next;
}

void Node::setNext(Node* next){
	this->next = next;
}
