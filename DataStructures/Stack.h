#pragma once

#include <stdexcept>

template <typename T>
class Stack
{
private:
	class Node {
	public:
		T data;
		Node* next;

		Node(const T& data, Node* next) {
			this->data = data;
			this->next = next;
		}
	};

	int length;
	Node* head;
public:
	Stack();
	Stack(const T& elem);
	~Stack();

	void clear();

	int size() const;
	bool isEmpty() const;

	void push(const T& data);
	T& pop();
	T& peek() const;
};

#include "Stack.inl"