#ifndef DLINKEDLIST_INL
#define DLINKEDLIST_INL

#include "DLinkedList.h"

template <typename T>
DLinkedList<T>::DLinkedList() {
	head = nullptr;
	tail = nullptr;
	length = 0;
}

template <typename T>
void DLinkedList<T>::clear() {
	if (length == 0)
		return;

	Node* next;

	while (head != nullptr) {
		next = head->next;
		delete head;
		head = next;
	}

	tail = nullptr;
	length = 0;
}

template <typename T>
int DLinkedList<T>::size() const{
	return length;
}

template <typename T>
bool DLinkedList<T>::isEmpty() const {
	return length == 0;
}

template <typename T>
void DLinkedList<T>::addFirst(const T& obj) {
	if (length == 0) {
		head = new Node(obj, nullptr, nullptr);
		tail = head;
	}
	else {
		head->prev = new Node(obj, nullptr, head);
		head = head->prev;
	}
	length++;
}

template <typename T>
void DLinkedList<T>::addLast(const T& obj) {
	if (length == 0) {
		head = new Node(obj, nullptr, nullptr);
		tail = head;
	}
	else {
		tail->next = new Node(obj, tail, nullptr);
		tail = tail->next;
	}
	length++;
}

template <typename T>
void DLinkedList<T>::addTo(int index, const T& obj) {
	if (index >= length)
		throw std::invalid_argument("Index is out of range");

	Node* elem = head;
	while (index > 0) {
		elem = elem->next;
		index--;
	}

	elem->prev->next = new Node(obj, elem->prev, elem);
	elem->prev = elem->prev->next;
	length++;
}

template <typename T>
T& DLinkedList<T>::get(int index) const {
	Node* elem = head;
	while (index > 0) {
		elem = elem->next;
		index--;
	}
	return elem->data;
}

template <typename T>
T& DLinkedList<T>::getFirst() const {
	return head->data;
}

template <typename T>
T& DLinkedList<T>::getLast() const {
	return tail->data;
}

template <typename T>
T& DLinkedList<T>::removeFirst() {
	if (length == 0)
		throw std::invalid_argument("List is empty");

	T data = head->data;

	Node* new_head = head->next;
	delete head;
	head = new_head;
	length--;

	return data;
}

template <typename T>
T& DLinkedList<T>::removeLast() {
	if (length == 0)
		throw std::invalid_argument("List is empty");

	T data = tail->data;

	Node* new_tail = tail->prev;
	delete tail;
	tail = new_tail;
	length--;
	
	return data;
}

template <typename T>
T& DLinkedList<T>::removeAt(int index) {
	if (length == 0)
		throw std::invalid_argument("List is empty");

	if (index == 0)
		return removeFirst();
	else if (index == length - 1)
		return removeLast();

	Node* elem;

	if (index < length / 2) {
		elem = head;

		while (index > 0) {
			elem = elem->next;
			index--;
		}
	}
	else {
		elem = tail;

		while ((length - 1) - index > 0) {
			elem = elem->prev;
			index++;
		}
	}

	T data = elem->data;

	elem->prev->next = elem->next;
	elem->next->prev = elem->prev;

	delete elem;
	length--;

	return data;
}

template <typename T>
bool DLinkedList<T>::remove(const T& obj) {
	if (length == 0)
		throw std::invalid_argument("List is empty");

	Node* elem = head;
	int index = 0;

	while (elem->data != obj) {
		if (elem->next == nullptr)
			return false;
		elem = elem->next;
		index++;
	}

	removeAt(index);
	return true;
}

template <typename T>
int DLinkedList<T>::find(const T& obj) const {
	if (length == 0)
		throw std::invalid_argument("List is empty");

	Node* elem = head;
	int index = 0;

	while (elem->data != obj) {
		if (elem->next == nullptr)
			return -1;
		elem = elem->next;
		index++;
	}

	return index;
}

template <typename T>
bool DLinkedList<T>::contains(const T& obj) const {
	return find(obj) != -1;
}

#endif
