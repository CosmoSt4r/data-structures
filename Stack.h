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

		Node(const T& _data, Node* _next) {
			data = _data;
			next = _next;
		}
	};

	int length;
	Node* head;
public:
	Stack();
	Stack(const T& elem);

	void clear();

	int size() const;
	bool isEmpty() const;

	void push(const T& data);
	T& pop();
	T& peek() const;
};

#include "Stack.inl"