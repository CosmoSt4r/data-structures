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

	int size() const;
	bool isEmpty() const;

	T& get(const int index) const;
	void set(const int index, const T& obj);
	void clear();

	void append(const T& obj);
	T& pop();

	int find(const T& obj);
	T& removeAt(const int index);
	bool remove(const T& obj);
};

#include "DynamicArray.inl"
