#pragma once
class PointerLinkedList
{
	class Node {
		int data;
		Node* next;
		public:

		Node() 
			: data(-1), next(nullptr) {}
		Node(int _data, Node* _next)
			: data(_data), next(_next) {}
		friend class PointerLinkedList;
	};
public:
	Node* Head = nullptr;
	Node* Tail = nullptr;
	void insertToTail(int data);

};

