#include "PointerLinkedList.h"

PointerLinkedList::~PointerLinkedList()
{
	Node* temp;
	beginIterator();
	while (iter.iter->next != nullptr) 
	{
		temp = iter.iter;
		iter.advanceIterator();
		delete temp;
	}
	delete iter.iter;
}

void PointerLinkedList::insertToTail (int data)
{
	Node* newNode = new Node(data, nullptr);
	if (Head == nullptr) 
	{
		Head = newNode;
		Tail = newNode;
	}
	else 
	{
		Tail->next = newNode;
		Tail = newNode;
	}
}