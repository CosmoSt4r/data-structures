#ifndef QUEUE_INL
#define QUEUE_INL

#include "Queue.h"

template <typename T>
Queue<T>::Queue() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template <typename T>
Queue<T>::Queue(const T& firstElem) {
	head = new Node(firstElem, nullptr);
	tail = head;
	length = 1;
}

template <typename T>
int Queue<T>::size() const{
	return length;
}

template <typename T>
bool Queue<T>::isEmpty() const {
	return length == 0;
}

template <typename T>
T& Queue<T>::peek() const {
	if (length == 0)
		throw std::invalid_argument("Queue is empty");
	return head->data;
}

template <typename T>
T& Queue<T>::pop() {
	if (length == 0)
		throw std::invalid_argument("Queue is empty");
	T data = head->data;

	Node* newHead = head->next;
	delete head;
	head = newHead;

	length--;

	return data;
}

template <typename T>
void Queue<T>::push(const T& data) {
	Node* newTail = new Node(data, nullptr);

	if (tail != nullptr)
		tail->next = newTail;
	tail = newTail;
	if (head == nullptr)
		head = tail;

	length++;
}

#endif