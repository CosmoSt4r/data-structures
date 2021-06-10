#include "Stack.h"

template <typename T>
Stack<T>::Stack() {
	head = nullptr;
	length = 0;
}

template <typename T>
Stack<T>::Stack(const T& elem) 
	: Stack(){
	push(elem);
}

template <typename T>
void Stack<T>::clear() {
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
	return length;
}

template <typename T>
bool Stack<T>::isEmpty() const {
	return length == 0;
}

template <typename T>
void Stack<T>::push(const T& data) {
	Node* node = new Node(data, head);
	head = node;
	length++;
}

template <typename T>
T& Stack<T>::pop() {
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
	if (length == 0)
		throw std::invalid_argument("Stack is empty");
	return head->data;
}
