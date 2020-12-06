#pragma once
#include <iostream>
#include <memory>

class MyLinkedList
{
public:
	class Node
	{
	public:
		std::shared_ptr<Node> next;
		int value;

		// Insert into middle c'tor
		Node(std::shared_ptr<Node> next, int value) :
			next(std::move(next)), value(value)
		{
		}
	};

public:
	std::shared_ptr<Node> start = nullptr, end = nullptr;
	std::shared_ptr<Node> before_start = nullptr;

public:
	void print_all()
	{
		if (before_start == nullptr)
		{
			return;
		}

		std::shared_ptr<Node> current_node = before_start->next;

		while (current_node != end)
		{
			std::cout << current_node->value << ' ';
			current_node = current_node->next;
		}

		std::cout << std::endl;
	}

	void sorted_insert(int value)
	{
		if (start == nullptr)
		{
			start = std::make_shared<Node>(end, value);
			before_start = std::make_shared<Node>(start, 0);
			return;
		}

		auto last_node = before_start;

		for (auto current_node = start;
			 current_node != end;
			 last_node = current_node, current_node = current_node->next)
		{
			if (current_node->value >= value)
			{
				break;
			}
		}

		insert_after(last_node, value);
	}

	static void insert_after(std::shared_ptr<Node> node, int value)
	{
		node->next = std::make_shared<Node>(node->next, value);
	}

	void remove()
};
