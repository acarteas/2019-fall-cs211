#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <vector>
#include <unordered_map>
#include <cctype>
using namespace std;

class TrieNode
{
private:
    char _data;
    unordered_map<char, TrieNode*> _children;

	//For our Trie, we are using the character '$' as a sentinel
	//value to mark the end of a word.
    static const char _sentinel = '$';

public:
    TrieNode(const char &data = '\0')
    {
        setValue(data);
    }

    void setValue(const char &data)
    {
        _data = toupper(data);
    }

    const char& getValue() const
    {
        return _data;
    }

    char& getValue()
    {
        return _data;
    }

	//Returns true if the current Trie node represents the end of
	//a word.
    bool isWord() const
    {
		_children.find(_sentinel) != _children.end();
    }

	//Returns true when the current Trie node has the value of 
	//the sentiel node
    bool isSentinel() const
    {
        return _data == _sentinel;
    }

	//returns true when the Trie node has at least one child
    bool hasChild(char index) const
    {
		return _children.find(index) != _children.end();
    }

    void setChild(char index, TrieNode *node)
    {
        _children[index] = node;
    }

    TrieNode* getChild(char index)
    {
        return _children[index];
    }

	//returns a list of children.
	unordered_map<char, TrieNode*> getChildren()
	{
        return _children;
    }

};

#endif // !TRIE_NODE_H
