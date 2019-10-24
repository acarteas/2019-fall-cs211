#pragma once
#include "BinarySearchTree.hpp"

template <typename T>
class AvlNode : public BinaryNode<T>
{
	//BAD PRACTICE!
	//instead, we know to make variables private and
	//allow restricted access via getters and setters
public:
	int height = -1;
};

class AvlTree : public BinarySearchTree<T>
{

};