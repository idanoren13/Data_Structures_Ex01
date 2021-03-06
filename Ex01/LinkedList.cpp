#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList(int size)
{
	list = new Node[size];
	this->size = size;
	headList = 0;
	headFree = 0;
}

void LinkedList::Insert(int data) 
{
	if (headFree == headList) //list is empty
	{
		list[0].data = data;
		headFree++;
	}

	else
	{
		list[headFree].data = data;
		list[headFree - 1].nextNode = headFree;
		headFree++;
	}
}

int LinkedList::GetNode(int index)
{
	return list[index].data;
}

void LinkedList::PrintList()
{
	int i = 0;
	
	while (i < headFree)
	{
		printf("%d", list[i].data);
		i++;
	}
}

