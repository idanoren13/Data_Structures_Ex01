#pragma once
class LinkedList
{
	struct Node
	{
		int data;            // In our case - number of the city
		int nextNode = -1;   //  The index to the next node
	};

	Node* list=nullptr;
	int size;
	int headList;      // Index to the first node in the list
	int headFree;      // Index to the next available spot

public:

	LinkedList(int size);
	void Insert(int data);
	int GetNode(int index);
	void PrintList();


	~LinkedList()
	{
		delete[] list;
	}
};