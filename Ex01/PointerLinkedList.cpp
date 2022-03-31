#include "PointerLinkedList.h"

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