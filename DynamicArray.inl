#ifndef DARRAY_INL
#define DARRAY_INL

#include <stdexcept>
#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray() {
	length = 0;
	capacity = 16;
}

template <typename T>
DynamicArray<T>::DynamicArray(const int new_capacity) {
	if (new_capacity < 0) {
		throw std::invalid_argument("Capacity can't be less than zero");
	}
	capacity = new_capacity;
	delete[] array;
	array = new T[capacity];
	length = 0;
}

template <typename T>
int DynamicArray<T>::size() const {
	return length;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const {
	return size() == 0;
}

template <typename T>
T& DynamicArray<T>::get(const int index) const {
	if (index < 0 || index >= length) {
		throw std::invalid_argument("Index is out of range");
	}
	return array[index];
}

template <typename T>
void DynamicArray<T>::set(const int index, const T& obj) {
	if (index < 0 || index > length - 1) {
		throw std::invalid_argument("Index is out of range");
	}
	array[index] = obj;
}

template <typename T>
void DynamicArray<T>::clear() {
	delete[] array;
	array = new T[capacity];
	length = 0;
}

template <typename T>
void DynamicArray<T>::append(const T& obj) {
	if (length+1 >= capacity) {
		if (capacity == 0) capacity = 1;
		else capacity = capacity << 1;

		T* new_array = new T[capacity];
		for (int i = 0; i < capacity; ++i) {
			new_array[i] = array[i];
		}
		delete[] array;
		array = new_array;
	}
	array[length++] = obj;
}

template <typename T>
T& DynamicArray<T>::pop() {
	if (isEmpty())
		throw std::invalid_argument("Array is empty");
	T obj = array[--length];
	array[length] = NULL;
	return obj;
}

template <typename T>
int DynamicArray<T>::find(const T& obj) const{
	for (int i = 0; i < length; ++i) {
		if (array[i] == obj)
			return i;
	}
	return -1;
}

template <typename T>
bool DynamicArray<T>::contains(const T& obj) const {
	return find(obj) != -1;
}

template <typename T>
T& DynamicArray<T>::removeAt(const int index) {
	if (index < 0 || index > length - 1) {
		throw std::invalid_argument("Index is out of range");
	}
	T obj = array[index];
	for (int i = index; i < length; ++i) {
		array[i] = array[i + 1];
	}
	pop();
	return obj;
}

template <typename T>
bool DynamicArray<T>::remove(const T& obj) {
	int index = find(obj);

	if (index != -1) {
		removeAt(index);
		return true;
	}
	return false;
}

#endif