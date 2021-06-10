#pragma once

#include <stdexcept>
#include <iostream>

template <typename T>
class DynamicArray
{
private:
	T* array;
	int length;
	int capacity;

	void swap(T* left, T* right);
	void quickSort(int low, int high);
public:
	DynamicArray();
	DynamicArray(const int new_capacity);

	int size() const;
	bool isEmpty() const;

	T& get(const int index) const;
	void set(const int index, const T& obj);
	void sort(bool reversed = false);
	void sortRange(int low, int high, bool reversed = false);
	void clear();

	void append(const T& obj);
	T& pop();

	int find(const T& obj) const;
	bool contains(const T& obj) const;
	T& removeAt(const int index);
	bool remove(const T& obj);

	T* begin();
	T* end();
};

#include "DynamicArray.inl"
