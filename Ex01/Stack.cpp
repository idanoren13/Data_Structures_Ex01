#include "Stack.h"

Stack::~Stack() {
	makeEmpty();
}

void Stack::makeEmpty() {
	while (Top) {
		type temp = pop();
	}
}
void Stack::push(const type data) {
	Top = new Node(data, Top);
}

type Stack::pop() {
	Node* temp = Top;
	type item = temp->data;
	Top = Top->Next;
	temp->Next = nullptr;
	delete temp;
	return item;
}

type Stack::top() {
	return Top->data;
}

