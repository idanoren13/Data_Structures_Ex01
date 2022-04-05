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
	/*
	*	TODO: add iterator, add get iterator data
	*/
	class Iterator 
	{
		Node* iter;
		friend class PointerLinkedList;
	public:
		Iterator(Node* _iter = nullptr)
			: iter(_iter) {}

		Iterator operator++()
		{
			if (iter != nullptr) {
				iter = iter->next;
				return *this;
			}
			else {
				throw "ERROR: The linked list iterator is null";
			}
		}

		int getData() { return iter->data; }
	};
	Iterator Begin() { return Head; }
};

