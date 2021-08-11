#pragma once

#include <stdexcept>

template <typename T>
class Queue
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

	Node* head;
	Node* tail;
	int length;

public:
	Queue();
	Queue(const T& firstElem);
	~Queue();

	int size() const;
	bool isEmpty() const;

	T& peek() const;
	T& pop();
	void push(const T& data);
};

#include "Queue.inl"