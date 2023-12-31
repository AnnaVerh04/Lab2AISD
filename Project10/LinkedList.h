#include <iostream>
#include <random>

inline int random(int x, int y) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(x, y);
	return dist(gen);
}

struct list_exception {};

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

	void clear() {
		while (head != nullptr) {
			pop_head();
		}
	}

public:
	LinkedList(): head(nullptr), tail(nullptr), size(0) {}

	LinkedList(const LinkedList<T>& other) {
		if (other.head != nullptr) {
			Node* current_other = other.head;
			int i = 0;
			while (i < other.size) {
				push_tail(current_other->data);
				current_other = current_other->next;
				++i;
			}

			size = other.size;
		}
	}

	LinkedList(int count, int x, int y) {
		if (x > y) {
			throw list_exception(); 
		}
		int generated_num = random(x, y);
		int i = 0;
		while (i < count)
		{
			push_tail(generated_num);
			generated_num = random(x, y);
			++i;
		}
	}

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

	void push_head(const T& value) {
		Node* new_node = new Node(value);
		++size;
		if (head == nullptr) {
			head = tail = new_node;
			head->next = head;
		}
		else {
			new_node->next = head;
			head = new_node;
			tail->next = head;
		}
	}

	void push_head(const LinkedList<T>& other) {
		if (other.head != nullptr) {
			LinkedList<T> temp_list;
			temp_list = *this;
			clear();                                        
			*this = other;
			push_tail(temp_list);
		}
	}

	LinkedList& operator=(const LinkedList<T>& other) {
		if (this != &other) {
			clear();  
			
			if (other.head != nullptr) {
				Node* current_other = other.head;
				int i = 0;
				while (i < other.size) {
					push_tail(current_other->data);
					current_other = current_other->next;
					++i;
				}
				size = other.size;
			}
		}
		return *this;
	}

	void pop_head() {
		if (head == nullptr)
		{
			throw list_exception();
		}
		--size;

		if (head->next == head)
		{
			delete head;
			head = tail = nullptr;
		}
		else 
		{
			Node* temp = head;
			head = head->next;
			tail->next = head;
			delete temp;
		}
	}

	void pop_tail() {
		if (head == nullptr)
		{
			throw list_exception();
		}
		--size;

		if (head->next == head)
		{
			delete head;
			head = tail = nullptr;
		}
		else
		{
			Node* current = head;
			int i = 0;
			while (i != size - 1) {
				current = current->next;
				++i;
			}

			Node* delete_tail = tail;
			tail = current;
			tail->next = head;
			delete delete_tail;
		}
	}

	void delete_node(const T& value) {
		if (head == nullptr)
		{
			throw list_exception();
 		}

		Node* current = head;
		Node* previous = nullptr;

		int i = 0;

		while (i < size)
		{
			if (current->data == value) {
				if (current == head)
				{
					pop_head();
					current = head;
					continue;
				}
				else if (current == tail) 
				{
					pop_tail();
					break;
				}
				else
				{
					previous->next = current->next;
					delete current;
					--size;
					current = previous->next;
					continue;
				}
			}

			previous = current;
			current = current->next;
			++i;
		}
	}

	const T& operator[](int index) const {
		if (index > size - 1)
		{
			throw list_exception();
		}

		Node* current = head;
		for (size_t i = 0; i < index; ++i)
		{
			current = current->next;
		}

		return current->data;
	}

	 T& operator[](int index)  {
		if (index > size - 1)
		{
			throw list_exception();
		}

		Node* current = head;
		for (size_t i = 0; i < index; ++i)
		{
			current = current->next;
		}

		return current->data;
	 }

	 void print() const {
		 if (head == nullptr) {
			 throw list_exception();
		 }

		 Node* current = head;
		 int i = 0;
		 while (i < size) {
			 std::cout << current->data << " ";
			 current = current->next;
			 ++i;
		 }
		 std::cout << "\n";
	 }

	 ~LinkedList() {
		 clear();
	 }

};
