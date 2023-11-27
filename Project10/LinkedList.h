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


public:
	LinkedList(): head(nullptr), tail(nullptr), size(0) {}

	void push_tail(const T& value) {
		Node* new_node = new Node(value);
		++size;
		if (head == nullptr) {
			head = tail = new_node;
			head->next = head;
		}
		else {
			tail->next = new_node;
			tail = new_node;
			tail->next = head;
		}
	}

	void push_tail(const LinkedList<T>& other) {
		if (other.head != nullptr) {
			Node* current_other = other.head;
			int i = 0;
			while (i<other.size)
			{
				push_tail(current_other->data);
				current_other = current_other->next;
				++i;
			}
		}
	}


};
