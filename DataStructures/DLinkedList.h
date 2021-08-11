#pragma once

#include <stdexcept>

template <typename T>
class DLinkedList
{
private:
	class Node {
	public:
		T data;
		Node* next;
		Node* prev;

		Node(T data, Node* prev, Node* next) {
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
	};

	int length;
	Node* head;
	Node* tail;
public:
	DLinkedList();
	~DLinkedList();

	void clear();

	int size() const;
	bool isEmpty() const;

	void addFirst(const T& obj);
	void addLast(const T& obj);
	void addTo(int index, const T& obj);

	T& get(const int index) const;
	T& getFirst() const;
	T& getLast() const;

	T& removeFirst();
	T& removeLast();
	T& removeAt(const int index);
	bool remove(const T& obj);
	
	void invert();
	int find(const T& obj) const;
	bool contains(const T& obj) const;
};


#include "DLinkedList.inl"
