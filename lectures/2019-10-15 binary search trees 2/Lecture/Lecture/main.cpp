#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <list> //Doubly-linked list
#include <stack>
#include <queue>
#include <deque>
#include <sstream> //for istringstream
#include <unordered_map>

using namespace std;

template <typename T>
class BinaryNode
{
	//BAD PRACTICE!
	//instead, we know to make variables private and
	//allow restricted access via getters and setters
public:
	T value;
	BinaryNode<T>* left = nullptr;
	BinaryNode<T>* right = nullptr;
};

template<typename T>
class BinarySearchTree
{
private:
	BinaryNode<T>* _root = nullptr;
	int _size = 0;

	BinaryNode<T>* addValue(const T& value, BinaryNode<T>* node)
	{
		//always handle base case first!
		//base case: null pointer -> we need to create a new node!
		if (node == nullptr)
		{
			node = new BinaryNode<T>{};
			node->value = value;
			return node;
		}

		//recursive case: use BST rules to place the value in the
		//correct location (ask: where does new value belong?)
		if (value < node->value)
		{
			//belongs on left
			BinaryNode<T>* left = addValue(value, node->left);
			node->left = left;
		}
		else
		{
			//belongs on right
			BinaryNode<T>* right = addValue(value, node->right);
			node->right = right;
		}
		return node;

	}
	void addValue_iter(const T& value)
	{
		BinaryNode<T>* current = _root;
		while (current != nullptr)
		{
			if (value < current->value)
			{
				//left side
				if (current->left == nullptr)
				{
					break;
				}
				else
				{
					current = current->left;
				}
			}
			else
			{
				//right side
				if (current->right == nullptr)
				{
					break;
				}
				else
				{
					current = current->right;
				}
			}
		}

		//when done with loop, current will either be nullptr
		//or it will not
		//when current is nullptr, our tree is empty
		if (current == nullptr)
		{
			_root = new BinaryNode<T>{};
			_root->value = value;
		}
		else
		{
			//where does new value belong?
			if (value < current->value)
			{
				current->left = new BinaryNode<T>{};
				current->left->value = value;
			}
			else
			{
				current->right = new BinaryNode<T>{};
				current->right->value = value;
			}
		}
	}

	BinaryNode<T>* findSmallest(BinaryNode<T>* node)
	{
		BinaryNode<T>* current = node;
		while (current != nullptr && current->left != nullptr)
		{
			current = current->left;
		}
		return current;
	}

	BinaryNode<T>* removeValue(const T& value, BinaryNode<T>* node)
	{
		//base case: node is nullptr
		if (node == nullptr)
		{
			//empty tree or or value not in tree
			return node;
		}

		//base case: value is us!
		if (value == node->value)
		{
			//three possible configurations at current node
			//leaf node
			//OR internal node (one child)
			//OR internal node (two children)
			if (node->left == nullptr && node->right == nullptr)
			{
				delete node;
				return nullptr;
			}
			else if (node->left == nullptr || node->right == nullptr)
			{
				BinaryNode<T>* child = (node->left != nullptr)
					? node->left
					: node->right;
				delete node;
				return child;
			}
			else
			{
				//two children -> find smallest on right-hand side
				BinaryNode<T>* smallest = findSmallest(node->right);

				//take this node's value
				node->value = smallest->value;

				//continue delete operation with new value to delete
				BinaryNode<T>* result = removeValue(node->value, node->right);
				node->right = result;
			}
		}
		else if (value < node->value)
		{
			BinaryNode<T>* result = removeValue(value, node->left);
			node->left = result;
		}
		else
		{
			BinaryNode<T>* result = removeValue(value, node->right);
			node->right = result;
		}
		return node;
	}
	
public:

	void addValue(const T& value)
	{
		_root = addValue(value, _root);
		_size++;
	}

	void removeValue(const T& value)
	{
		_root = removeValue(value, _root);

		//problem: no way of knowing if value was actually deleted
		_size--;
	}

	int getSize() const
	{
		return _size;
	}
};

int main(int argc, char* argv[])
{
	BinarySearchTree<int> tree{};
	for (int i = 0; i < 15; i++)
	{
		tree.addValue(rand() % 100);
	}

	//tests:
	//remove node w/ 2 children
	tree.removeValue(41);

	//remove node w/ 1 child
	tree.removeValue(0);

	//remove node w/ 0 children
	tree.removeValue(81);
}