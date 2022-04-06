#pragma once

enum Line { IS_WHITE, IS_BLACK, AFTER_SECOND, AFTER_THIRD };

struct type {
	int city;
	Line colorLabel;

};
class Stack
{
public:
	class Node {
		type data;
		Node* Next;
	public:
		Node()
			: data(), Next(nullptr) {}
		Node(type _data, Node* _Next) { data = _data; Next = _Next; }
		friend class Stack;
	};

public:

	Node* Top;
	Stack() :
		Top(nullptr) {};
	~Stack();
	void makeEmpty();
	bool isEmpty() { return Top == nullptr; }

	void push(const type data);

	type pop();
	type top();

};