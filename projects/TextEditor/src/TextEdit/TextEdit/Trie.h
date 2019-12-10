#pragma once


#include "TrieNode.h"
#include <string>
#include <cctype>
using namespace std;

class Trie
{
private:
	TrieNode* _root = nullptr;

protected:

public:

	// Constructor
	Trie()
	{
		_root = new TrieNode{};
	}

	// adds the input string to the trie tree
	void addWord(const string& word)
	{
		TrieNode* current_node = _root;
		for (char ch : word)
		{
			if (current_node->hasChild(ch))
			{
				current_node = current_node->getChild(ch);
			}
			else
			{
				TrieNode* new_node = new TrieNode(ch);
				current_node->setChild(ch, new_node);
				current_node = new_node;
			}
		}
		// Add a sentinel node at the end of the word
		TrieNode* sentinel_node = new TrieNode('$');
		current_node->setChild('$', sentinel_node);
	}

	// recursive helper function for search function
	void getWords(vector<string>* words, string prefix, TrieNode* node)
	{
		unordered_map<char, TrieNode*> children = node->getChildren();
		for (pair<char, TrieNode*> node_pair : children)
		{
			TrieNode* child_node = node_pair.second;
			char child_val = node_pair.first;
			if (child_val == '$')
			{
				words->push_back(prefix);
				continue;
			}
			string new_prefix = prefix + child_val;
			getWords(words, new_prefix, child_node);
		}
	}

	// finds word completions for the provided prefix
	vector<string> search(const string& word)
	{
		vector<string> matches;
		TrieNode* current_node = _root;

		// check to see if provided word is empty
		if (word.empty())
		{
			return matches;
		}

		// iterating through the supplied letters
		for (char ch : word)
		{
			if (current_node->hasChild(ch))
			{
				current_node = current_node->getChild(ch);
			}
			else
			{
				return matches;
			}
		}

		// from the last point in the supplied letters,
		// finding all valid completions to the word
		getWords(&matches, word, current_node);

		return matches;
	}
};
