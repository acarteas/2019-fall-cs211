#ifndef TRIE_H
#define TRIE_H

#include "TrieNode.h"
#include <string>
#include <cctype>
#include <vector>
using namespace std;

class Trie
{
private:
	TrieNode* _root = nullptr;
protected:

public:
	Trie()
	{
		_root = new TrieNode{};
	}

	virtual ~Trie()
	{
		//clean up memory
	}

	void addWord(const string& word)
	{
		TrieNode* current = _root;
		for (int i = 0; i < word.length(); i++)
		{
			char ch = word.at(i);
			if (!current->hasChild(word.at(i)))
			{
				TrieNode* node = new TrieNode{ch};
				current->setChild(ch, node);
			}
			current = current->getChild(ch);
		}
		TrieNode* node = new TrieNode{ '$' };
		current->setChild('$', node);
	}


	vector<string> search(const string& word)
	{
		vector<string> matches{};
		TrieNode* temp = _root;
		if (temp != nullptr) {
			matches = search(word);
		}

		//strip the $ off of every word
		for (int i = 0; i < matches.size(); i++) {
			string newString = matches[i].substr(0, matches[i].length() - 1);
			matches[i] = newString;
		}
		return matches;
	}

};
#endif // !TRIE_H