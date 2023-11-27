#include <iostream>


template <typename T>
class LinkedList {
private:
	struct Node
	{
		T data;
		Node* next;

		Node() : data(), next(nullptr) {}
		Node(const T& value) : data(value), next(nullptr){}
	};

	Node* head;
	Node* tail;
	int size;
};
