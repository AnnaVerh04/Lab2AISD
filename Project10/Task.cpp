#include <iostream>
#include <random>
#include "LinkedList.h"

int main() {
	int N;
	std::cout << "Enter the value of N: ";
	std::cin >> N;

	LinkedList<int> list;

	if (N < 1) {
		//error
	}

	int generated_num = 2;
	while (generated_num <= N)
	{
		list.push_tail(generated_num);
		++generated_num;
	}

	int p = 2;
	while (p * p <= N) {
		for (int i = p * p; i <= N; i += p) {
			list.delete_node(i);
		}
		++p;
	}

	std::cout << "Prime numbers up to " << N << ": ";
	list.print();
}