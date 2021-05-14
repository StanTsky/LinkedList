#pragma once

#include "Node.h"

class LinkedList
{
private:
	Node *first;

public:
	LinkedList();
	bool isEmpty();
	void addFront(int value);
	void addBack(int value);
	void removeFront();
	void removeBack();
	Node *find(int value);
	// bool delNode(int value);
	Node *findAgain(int value);
	void removeDuplicates();
	int countNodes();
	void display();
};