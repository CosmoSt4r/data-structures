#ifndef DARRAY_INL
#define DARRAY_INL

#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray() {
	length = 0;
	capacity = 16;
}

template <typename T>
DynamicArray<T>::DynamicArray(const int new_capacity) {
	capacity = new_capacity;
	delete[] array;
	array = new T[capacity];
	length = 0;
}

#endif