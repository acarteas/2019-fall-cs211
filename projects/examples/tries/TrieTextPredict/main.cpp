#include <string>
#include <iostream>
#include "Trie.h"
using namespace std;

int main(void)
{
    Trie dictionary{};

    string line = "";
	dictionary.addWord("abc");
	dictionary.addWord("aabc");
	dictionary.addWord("def");
	vector<string> result = dictionary.search("a");

	//expected result:  "abc", "aabc"
	for (auto item : result)
	{
		cout << item << endl;
	}
}