#ifndef STACK_INL
#define STACK_INL

#include "Stack.h"

template <typename T>
Stack<T>::Stack() {
	// Default constructor

	head = nullptr;
	length = 0;
}

template <typename T>
Stack<T>::Stack(const T& elem) 
	: Stack(){
	// Constructor with initial element

	push(elem);
}

template <typename T>
void Stack<T>::clear() {
	// Clear stack

	if (length == 0)
		return;

	Node* next;

	while (head != nullptr) {
		next = head->next;
		delete head;
		head = next;
	}
	length = 0;
}

template <typename T>
int Stack<T>::size() const {
	// Get size of the stack

	return length;
}

template <typename T>
bool Stack<T>::isEmpty() const {
	// Check if stack is empty

	return length == 0;
}

template <typename T>
void Stack<T>::push(const T& data) {
	// Add new element to the stack

	Node* node = new Node(data, head);
	head = node;
	length++;
}

template <typename T>
T& Stack<T>::pop() {
	// Get last element from the stack

	if (length == 0)
		throw std::invalid_argument("Stack is empty");

	T data = head->data;

	Node* new_head = head->next;
	delete head;
	length--;

	head = new_head;
	return data;
}

template <typename T>
T& Stack<T>::peek() const {
	// Get last element without deleting it from the stack

	if (length == 0)
		throw std::invalid_argument("Stack is empty");
	return head->data;
}

#endif
