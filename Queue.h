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

		Node(const T& _data, Node* _next) {
			data = _data;
			next = _next;
		}
	};

	Node* head;
	Node* tail;
	int length;

public:
	Queue();
	Queue(const T& firstElem);

	int size() const;
	bool isEmpty() const;

	T& peek() const;
	T& poll();
	void offer(const T& data);
};

#include "Queue.inl"