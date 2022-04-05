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

		void advanceIterator()
		{
			if (iter != nullptr) {
				iter = iter->next;
			}
			else {
				throw "ERROR: The linked list iterator is null";
			}
		}
		friend inline bool operator!=(const Iterator& a, const Iterator& b)
		{
			return a.iter != b.iter;
		}

		int getData() { return iter->data; }
	};
	Iterator iter;
	void beginIterator() { iter.iter = Head; }
};

