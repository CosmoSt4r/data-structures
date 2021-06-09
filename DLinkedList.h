#pragma once

template <typename T>
class DLinkedList
{
private:
	class Node {
	public:
		T data;
		Node* next;
		Node* prev;

		Node(T _data, Node* _prev, Node* _next) {
			data = _data;
			prev = _prev;
			next = _next;
		}
	};

	int length;
	Node* head;
	Node* tail;
public:
	DLinkedList();

	void clear();

	int size() const;
	bool isEmpty() const;

	void addFirst(const T& obj);
	void addLast(const T& obj);
	void addTo(int index, const T& obj);

	T& get(const int index) const;
	T& getFirst() const;
	T& getLast() const;

	T& removeAt(const int index);
	T& removeFirst();
	T& removeLast();
};


#include "DLinkedList.inl"
