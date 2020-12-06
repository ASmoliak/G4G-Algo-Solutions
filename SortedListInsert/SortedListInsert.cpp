#include <iostream>
#include "MyLinkedList.h"

int main()
{
	MyLinkedList my_list;

	my_list.print_all();
	my_list.sorted_insert(2);
	my_list.print_all();
	my_list.sorted_insert(3);
	my_list.print_all();
	my_list.sorted_insert(1);
	my_list.print_all();
	my_list.sorted_insert(5);
	my_list.print_all();
	my_list.sorted_insert(6);
	my_list.print_all();
}

// Using STL
//void insert_sorted(std::forward_list<int>& list, int val)
//{
//	auto last_iterator = list.before_begin();
//
//	for (auto iterator = list.begin(); iterator != list.end(); last_iterator = iterator++)
//	{
//		if (*iterator >= val)
//		{
//			break;
//		}
//	}
//
//	list.insert_after(last_iterator, val);
//}