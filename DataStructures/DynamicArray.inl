#ifndef DARRAY_INL
#define DARRAY_INL

#include "DynamicArray.h"

template <typename T>
void DynamicArray<T>::swap(T* left, T* right) {
	// Swap values of two elements

	T temp = *left;
	*left = *right;
	*right = temp;
}

template <typename T>
void DynamicArray<T>::quickSort(int low, int high) {
	// Quick sort implementation (recursive)

	if (low < high) {
		T pivot = array[high];
		int i = (low - 1);

		for (int j = low; j <= high - 1; j++)
		{
			if (array[j] < pivot)
			{
				i++;
				swap(&array[i], &array[j]);
			}
		}
		swap(&array[i + 1], &array[high]);

		int pivot_index = (i + 1);

		quickSort(low, pivot_index - 1);
		quickSort(pivot_index + 1, high);
	}
}

template <typename T>
DynamicArray<T>::DynamicArray() {
	// Default constructor

	array = new T[16];
	length = 0;
	capacity = 16;
}

template <typename T>
DynamicArray<T>::DynamicArray(const int capacity) {
	// Constructor with specified capacity

	if (capacity < 0) {
		throw std::invalid_argument("Capacity can't be less than zero");
	}
	this->capacity = capacity;
	array = new T[capacity];
	length = 0;
}

template <typename T>
DynamicArray<T>::DynamicArray(T elements[], const int arr_size) 
	: DynamicArray(arr_size << 1){
	// Constructor from existing array
	
	for (int i = 0; i < arr_size; i++) {
		append(elements[i]);
	}
}

template <typename T>
int DynamicArray<T>::size() const {
	// Get size of array

	return length;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const {
	// Check if array is empty

	return size() == 0;
}

template <typename T>
T& DynamicArray<T>::get(const int index) const {
	// Get element of array by index

	if (index < 0 || index >= length) {
		throw std::invalid_argument("Index is out of range");
	}
	return array[index];
}

template <typename T>
void DynamicArray<T>::set(const int index, const T& obj) {
	// Set new element at specified index

	if (index < 0 || index > length - 1) {
		throw std::invalid_argument("Index is out of range");
	}
	array[index] = obj;
}

template <typename T>
void DynamicArray<T>::sort(bool reversed) {
	// Sort whole array

	if (reversed)
		quickSort(length - 1, 0);
	else
		quickSort(0, length - 1);
}

template <typename T>
void DynamicArray<T>::sortRange(int low, int high, bool reversed) {
	// Sort specified range of array

	if (low < 0 || low >= length)
		throw std::invalid_argument("Low index is out of range");
	if (high < 0 || high >= length)
		throw std::invalid_argument("High index is out of range");

	if (reversed)
		quickSort(high, low);
	else
		quickSort(low, high);
}

template <typename T>
void DynamicArray<T>::clear() {
	// Delete all elements in array

	delete[] array;
	array = new T[capacity];
	length = 0;
}

template <typename T>
void DynamicArray<T>::append(const T& obj) {
	// Add new element to the end of array

	if (length+1 >= capacity) {
		if (capacity == 0)
			capacity = 1;
		else
			capacity = capacity << 1;

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
	// Get last element of the array

	if (isEmpty())
		throw std::invalid_argument("Array is empty");
	T obj = array[--length];
	array[length] = NULL;
	return obj;
}

template <typename T>
int DynamicArray<T>::find(const T& obj) const{
	// Find index of specified element

	for (int i = 0; i < length; ++i) {
		if (array[i] == obj)
			return i;
	}
	return -1;
}

template <typename T>
bool DynamicArray<T>::contains(const T& obj) const {
	// Check if element is in array

	return find(obj) != -1;
}

template <typename T>
T& DynamicArray<T>::removeAt(const int index) {
	// Remove element from array in specified index

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
	// Remove first appearance of specified element

	int index = find(obj);

	if (index != -1) {
		removeAt(index);
		return true;
	}
	return false;
}

template <typename T>
T* DynamicArray<T>::begin() {
	// begin() method for iterator

	return &array[0];
}

template <typename T>
T* DynamicArray<T>::end() {
	// end() method for iterator

	return &array[length];
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const DynamicArray<T>& arr) {
	// Stream output overload for DynamicArray class

	if (arr.size() == 0)
		return stream;

	stream << "[";
	for (int i = 0; i < arr.size() - 1; ++i) {
		stream << arr.get(i) << ", ";
	}
	stream << arr.get(arr.size() - 1) << "]";
	return stream;
}

#endif