#pragma once

template <typename T>
class DynamicArray
{
private:
	T* array = new T[16];
	int length;
	int capacity;
public:
	DynamicArray();
	DynamicArray(const int new_capacity);
};

#include "DynamicArray.inl"
