#pragma once
#include <algorithm>
#include <stack>

struct Node
{
	Node* left = nullptr, * right = nullptr;
	size_t value;

	Node(size_t value) :
		value(value)
	{
	}

	Node* insertLeft(Node* node)
	{
		return (left = node);
	}

	Node* insertRight(Node* node)
	{
		return (right = node);
	}

	bool isDeadEnd() const
	{
		return left == nullptr && right == nullptr;
	}
};

class BinaryTree
{
public:
	Node* head;

	BinaryTree(size_t head_value) :
		head(new Node(head_value))
	{
	}

	~BinaryTree()
	{
		std::stack<Node*> last_nodes;

		Node* current_node = head;

		while (true)
		{
			if (current_node->left != nullptr)
			{
				last_nodes.push(current_node);
				current_node = current_node->left;
				continue;
			}
			else if (current_node->right != nullptr)
			{
				last_nodes.push(current_node);
				current_node = current_node->right;
				continue;
			}
			else
			{
				if (last_nodes.empty())
				{
					delete current_node;
					break;
				}

				auto last_node = last_nodes.top();
				if (last_node->left == current_node)
				{
					last_node->left = nullptr;
				}
				else if (last_node->right == current_node)
				{
					last_node->right = nullptr;
				}

				delete current_node;
				current_node = last_node;
				last_nodes.pop();
			}
		}
	}

	size_t findMinDepth(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		if (node->isDeadEnd())
		{
			return 1;
		}

		if (node->left == nullptr)
		{
			return findMinDepth(node->right) + 1;
		}

		if (node->right == nullptr)
		{
			return findMinDepth(node->left) + 1;
		}

		return std::min(findMinDepth(node->left), findMinDepth(node->right)) + 1;
	}

	size_t findMaxDepth(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		if (node->isDeadEnd())
		{
			return 1;
		}

		if (node->left == nullptr)
		{
			return findMinDepth(node->right) + 1;
		}

		if (node->right == nullptr)
		{
			return findMinDepth(node->left) + 1;
		}

		return std::max(findMinDepth(node->left), findMinDepth(node->right)) + 1;
	}
};