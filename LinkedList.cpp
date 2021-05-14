#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList()
{
	first = new Node();
}

bool LinkedList::isEmpty()
{
	return first->next == nullptr;
}

void LinkedList::addFront(int value)
{
	//if (this->find(value) != nullptr)
	//	std::cout << "data " << value << " already exists!" << std::endl;
	//else
	//{
		// Create a new node with the input value
		Node *newNode = new Node(value);		// allocate object outside the function, by using a pointer

												// Attach new node to the list
		newNode->next = first->next;
		first->next = newNode;
		std::cout << "Added node " << first->next << " with data = " << newNode->data 
              << " to the front" << std::endl;
	//}
}

void LinkedList::addBack(int value)
{

	//if (this->find(value) != nullptr)
	//	std::cout << "data " << value << " already exists!" << std::endl;
	//else
	//{
		Node *temp = first;  // Declare a traversal pointer and start it at the beginning

		while (temp->next != nullptr)  // Find the end of the list
			temp = temp->next;

		// Create a new node with the new data
		Node *newNode = new Node(value);

		temp->next = newNode;  // Attach new node to end of list

		std::cout << "Added node " << temp->next << " with data = " << newNode->data 
              << " to the back" << std::endl;
	//}

}

void LinkedList::removeFront()
{
	// Point a temp pointer to the first node
	Node *temp = first->next;

	// Reassign dummy node's link to the following node
	first->next = temp->next;
	temp->next = nullptr;			

	// Delete the temp pointer
	delete temp;
}

void LinkedList::removeBack()
{	
	Node *trailer = first;						// Point trailer pointer to dummy	
	Node *temp = trailer->next;				// Point temp pointer to trailer's next
	
	while (temp->next != nullptr)			// Traverse list until temp is on last node
	{
		trailer = temp;							    // previous next address
		temp = temp->next;						  // current next address
	}

	trailer->next = nullptr;					// Set trailer's next to null	
	delete temp;								      // Delete temp
}

Node *LinkedList::find(int value)
{
	Node *temp = first->next;

	while (temp != nullptr)
	{
		if (temp->data == value)
			return temp;

		temp = temp->next;
	}

	return nullptr;
}

Node *LinkedList::findAgain(int value)
{
	int count = 0;					
	Node *temp = first->next;

	while (temp != nullptr)
	{
		if (temp->data == value)
		{
			count++;
			if (count > 1) 
				return temp;
		}
		temp = temp->next;
	}

	return nullptr;
}

void LinkedList::removeDuplicates()
{
	// adapted from code in
	// https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/

	Node *trailer = first;			// point trailer pointer to dummy
	Node *temp;									// temp node pointer
	Node *dupe;									// dupe node pointer

	// check that trailer is not empty and its next link is not empty
	while (trailer != nullptr) //  && trailer->next != nullptr
	{
		temp = trailer;							      // assign temp node to be trailer
		while (temp->next != nullptr)			// loop while temp node has a next node
		{
			if (trailer->data == temp->next->data)	// check if trailer data equals node after temp's data
			{
				dupe = temp->next;					      // if so, set dupe node to the node after temp
				temp->next = temp->next->next;		// set node after temp to skip one node
				std::cout << "Deleting duplicate node " << dupe << std::endl;
				delete(dupe);						    // delete the dupe node
			}
			else
				temp = temp->next;					// move temp node forward
		}
		trailer = trailer->next;				// move trailer node forward
	}
}

int LinkedList::countNodes()
{
	int counter = 0;
	Node *temp = first->next;

	while (temp != nullptr)
	{
		counter++;
		temp = temp->next;
	}
	return counter;
}

void LinkedList::display()
{
	Node *temp = first->next;

	while (temp != nullptr)
	{
		std::cout << temp->data << " ";
		//std::cout << "node " << temp << " with data " << temp->data << std::endl;
		temp = temp->next;
	}
	std::cout << std::endl;
}
