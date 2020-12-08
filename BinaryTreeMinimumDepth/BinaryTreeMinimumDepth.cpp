#include <iostream>

#include "BinaryTree.hpp"

int main()
{
	BinaryTree btree(1);

	auto left = btree.head->insertLeft(new Node(2));
	left->insertLeft(new Node(4));
	left->insertRight(new Node(5));

	btree.head->insertRight(new Node(3));

	std::cout << btree.findMinDepth(btree.head);
}