#include <iostream>
#include "DynamicArray.h"
#include "DLinkedList.h"
#include "Stack.h"
#include "Queue.h"

template <typename T>
void print(const T& data) {
	std::cout << data << std::endl;
}

int main() {

	DynamicArray<int> darray;
	DLinkedList<float> dllist;
	Stack<double> stack;
	Queue<char> queue;

	return 0;
}