#pragma once

template <typename T>
class DynamicArray
{
private:
	T* array = new T[16];
	int length;
	int capacity;

	void swap(T* left, T* right);
	int partition(int low, int high);
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
};

#include "DynamicArray.inl"
