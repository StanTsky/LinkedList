/*
--------------------------------------------------------------------
* Name:       Stan Turovsky
* Class:      Advanced C++
* Files:      main.cpp, LinkedList.cpp, LinkedList.h, Node.h
* Purpose:    Test program for the LinkedList class
*             -Nodes are added from different directions, then counted and listed
*             -Duplicates are found and removed, then nodes are counted again
*             -Nodes are then searched for a number twice 
*              to makes sure no duplicates are left
--------------------------------------------------------------------
*/

// Preprocessor directives
#include "LinkedList.h"
#include <iostream>
using namespace std;

int main()              // main function
{
	LinkedList list;

	if (list.isEmpty())
		cout << "List is empty" << endl;
	else
		cout << "List contains data" << endl;

	list.addBack(1);
	list.addBack(4);
	list.addBack(4);
	list.addFront(2);
	list.addFront(2);
	list.addBack(3);
	list.addFront(3);

	cout << "Node count: " <<  list.countNodes() << endl;

	if (list.isEmpty())
		cout << "List is empty" << endl;
	else
		cout << "List contains data" << endl;

	list.display();

	cout << "Removing duplicates" << endl;

	list.removeDuplicates();

	cout << "Node count: " << list.countNodes() << endl;

	list.display();

	Node *node = list.find(4);
	if (node == nullptr)
		cout << "Did not find 4." << endl;
	else
		cout << "Found 4." << endl;

	node = list.findAgain(4);
	if (node == nullptr)
		cout << "Did not find 4 more than once." << endl;
	else
		cout << "Found 4 more than once." << endl;

	//list.removeBack();
	//list.display();
	//list.removeFront();
	list.display();

	// Leave this stuff at the end.
	cout << endl;
	return 0;
}
