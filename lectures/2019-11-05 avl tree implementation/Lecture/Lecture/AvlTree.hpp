#pragma once
#include <cmath>
#include "BinarySearchTree.hpp"
using namespace std;
template <typename T>
class AvlNode : public BinaryNode<T>
{
	//BAD PRACTICE!
	//instead, we know to make variables private and
	//allow restricted access via getters and setters
public:
	int height = -1;
};

template <typename T>
class AvlTree : public BinarySearchTree<T>
{
protected:
	//will return the new root of the subtree
	virtual AvlNode<T>* rotateLeft(BinaryNode<T>* original_root)
	{
		if (original_root == nullptr)
		{
			return nullptr;
		}

		AvlNode<T>* new_root = dynamic_cast<AvlNode<T>*>(original_root->right);
		if (new_root != nullptr)
		{
			original_root->right = new_root->left;
			new_root->left = original_root;
		}

		//TODO: recalculate height of OR and NR
		setHeight(original_root);
		return setHeight(new_root);
	}

	//will return the new root of the subtree
	virtual AvlNode<T>* rotateRight(BinaryNode<T>* original_root)
	{
		if (original_root == nullptr)
		{
			return nullptr;
		}

		AvlNode<T>* new_root = dynamic_cast<AvlNode<T>*>(original_root->left);
		if (new_root != nullptr)
		{
			original_root->left = new_root->right;
			new_root->right = original_root;
		}

		//TODO: recalculate height of OR and NR
		setHeight(original_root);
		return setHeight(new_root);
	}
	int getBalanceFactor(BinaryNode<T>* node)
	{
		return getBalanceFactor(dynamic_cast<AvlNode<T>*>(node));
	}

	int getBalanceFactor(AvlNode<T>* node)
	{
		if (node == nullptr)
		{
			return 0;
		}
		AvlNode<T>* left = dynamic_cast<AvlNode<T>*>(node->left);
		AvlNode<T>* right = dynamic_cast<AvlNode<T>*>(node->right);
		int left_height = (left == nullptr) ? -1 : left->height;
		int right_height = (right == nullptr) ? -1 : right->height;
		return right_height - left_height;
	}

	virtual AvlNode<T>* setHeight(BinaryNode<T>* node)
	{
		return setHeight(dynamic_cast<AvlNode<T>*>(node));
	}

	virtual AvlNode<T>* setHeight(AvlNode<T>* node)
	{
		if (node == nullptr)
		{
			return node;
		}

		int height = 1;
		AvlNode<T>* left = dynamic_cast<AvlNode<T>*>(node->left);
		AvlNode<T>* right = dynamic_cast<AvlNode<T>*>(node->right);
		int left_height = (left == nullptr) ? -1 : left->height;
		int right_height = (right == nullptr) ? -1 : right->height;
		height += (left_height > right_height) ? left_height : right_height;
		node->height = height;

		//check for balance
		int root_balance_factor = getBalanceFactor(node);
		if (root_balance_factor > 1)
		{
			int new_root_balance_factor = getBalanceFactor(node->right);
			if (new_root_balance_factor < 0)
			{
				node->right = rotateRight(node->right);
			}
			return rotateLeft(node);
		}
		else if (root_balance_factor < -1)
		{
			int new_root_balance_factor = getBalanceFactor(node->left);
			if (new_root_balance_factor > 0)
			{
				node->left = rotateLeft(node->left);
			}
			return rotateRight(node);
		}

		//getting here means no rotation required
		return node;
	}

	virtual BinaryNode<T>* addValue(const T& value, BinaryNode<T>* node)
	{
		//always handle base case first!
		//base case: null pointer -> we need to create a new node!
		if (node == nullptr)
		{
			node = new AvlNode<T>{};
			node->value = value;
			return node;
		}

		//if not null, standard BST rules apply for inserts, so reuse!
		BinaryNode<T>* result = BinarySearchTree<T>::addValue(value, node);

		//because node creation occurs in this version of addValue,
		//result, should be an AvlNode
		AvlNode<T>* avl_result = dynamic_cast<AvlNode<T>*>(result);

		return setHeight(avl_result);

	}
};