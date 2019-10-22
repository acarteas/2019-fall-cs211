#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Trie.h"
using namespace std;

//build random trie of chars from 48-125
char getRandomChar()
{
	return rand() % 77 + 48;
}

void addToTrie(TrieNode* node)
{
	if (node == nullptr)
	{
		return;
	}
	char some_char = getRandomChar();
	
	//does trie have this value already?
	if (node->hasChild(some_char) == false)
	{
		//doesn't exist, add new trie node
		TrieNode* child = new TrieNode{ some_char };
		node->setChild(some_char, child);

		//randomly decide if we want to continue
		if (rand() % 3 > 0)
		{
			addToTrie(child);
		}
		else
		{
			child->setValue('$');
		}
	}
}

int main(void)
{

	TrieNode* root = new TrieNode{ };

	//make 100 calls (??? nodes) to the trie
	for (int i = 0; i < 100; i++)
	{
		addToTrie(root);
	}

	//pre-order walk:
	cout << root->getValue() << endl;
	for (auto child : root->getChildren())
	{
		cout << child.first << " " << child.second << endl;
	}
}