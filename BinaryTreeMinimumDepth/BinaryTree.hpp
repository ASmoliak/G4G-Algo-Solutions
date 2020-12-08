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
};

class BinaryTree
{
public:
	Node *head;

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

	void insertRight(Node* node)
	{
		Node* current_node = head;

		while (current_node->right != nullptr)
		{
			current_node = current_node->right;
		}

		current_node->right = node;
	}

	size_t findMinDepth(Node* node)
	{
		if (node == nullptr)
		{
			return 0;
		}

		return std::min(findMinDepth(node->left), findMinDepth(node->right));
	}
};

