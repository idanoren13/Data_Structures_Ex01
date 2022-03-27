#pragma once
template <class Data>
class LinkedList
{
public:
	class Node 
	{
	public:
		Data data;
		Node* next;
		friend class LinkedList;
	}
private:
	Node* head;

public:
	LinkedList() : head(nullptr) {}
	~LinkedList();
	void makeEmpty();
	Node getHead();
	void printList();
	void addNodeToTail(Data d);
	void addNewHead(Data d);
	void deleteNode(Node node);
	
};

