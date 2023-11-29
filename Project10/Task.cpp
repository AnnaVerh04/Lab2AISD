#include <iostream>
#include <random>
#include "LinkedList.h"

int main() {
	int N;
	std::cout << "Enter the value of N: ";
	std::cin >> N;

	LinkedList<int> list;

	if (N < 1) {
		throw list_exception();
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









	//LinkedList<int> list;
	//list.push_head(3);
	//list.push_tail(2);
	//list.push_head(5);
	//list.push_tail(1);

	//list.print();  //5321

	//list.delete_node(5);
	//list.print();    ///321

	/*LinkedList<int> list2;

	list2.push_head(1);
	list2.push_tail(5);
	list2.push_head(4);
	list2.push_tail(7);

	list2.print(); */ //4157

	///*list2 = list;
	//list2.print();*/ //5321

	//list.push_tail(list2);
	//list.print();  //53214157

	/*list.push_head(list2);
	list.print();*/  //41575321




	/*LinkedList<int> list(5,1,100);

	list.print();*/
