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
#include "BinarySearchTree.hpp"
#include "AvlTree.hpp"


using namespace std;


int main(int argc, char* argv[])
{
	BinarySearchTree<int>* tree = new AvlTree<int>{};
	for (int i = 0; i < 15; i++)
	{
		tree->addValue(i);
	}

	unordered_map<string, Traversal<int>*> traversals{
		make_pair("Pre Order", new PreOrderTraversal<int>{}),
		make_pair("In Order", new InOrderTraversal<int>{}),
		make_pair("Post Order", new PostOrderTraversal<int>{}),
		make_pair("Node Count", new NodeCounter<int>{}),
		make_pair("Is Full", new FullnessChecker<int>{}),
		make_pair("Level order traversal", new LevelOrderTraversal<int>{})
	};

}