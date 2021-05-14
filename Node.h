#pragma once

// template <class T>
class Node
{
public:
	int data;

	Node *next;

	Node() 
	{
		next = nullptr;
	}

	Node(int newValue)
	{
		data = newValue;
		next = nullptr;
	};
};