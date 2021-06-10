#ifndef DLINKEDLIST_INL
#define DLINKEDLIST_INL

#include "DLinkedList.h"

template <typename T>
DLinkedList<T>::DLinkedList() {
	// Default constructor

	head = nullptr;
	tail = nullptr;
	length = 0;
}

template <typename T>
void DLinkedList<T>::clear() {
	// Remove all elements from list

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
	// Get size of list

	return length;
}

template <typename T>
bool DLinkedList<T>::isEmpty() const {
	// Check if list is empty

	return length == 0;
}

template <typename T>
void DLinkedList<T>::addFirst(const T& obj) {
	// Add element to the head of the list

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
	// Add element to the back of the list

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
	// Add element to specified position of the list

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
	// Get element by index

	Node* elem = head;
	while (index > 0) {
		elem = elem->next;
		index--;
	}
	return elem->data;
}

template <typename T>
T& DLinkedList<T>::getFirst() const {
	// Get first element of the list

	return head->data;
}

template <typename T>
T& DLinkedList<T>::getLast() const {
	// Get last element of the list

	return tail->data;
}

template <typename T>
T& DLinkedList<T>::removeFirst() {
	// Remove first element of the list

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
	// Remove last element of the list

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
	// Remove element at specified index

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
	// Remove specified element from the list

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
	// Get index of specified element

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
	// Check if element is in list

	return find(obj) != -1;
}

#endif
