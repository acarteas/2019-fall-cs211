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

using namespace std;

void boringExamples()
{
	//reverse string using a stack
	stack<char> letters{};
	string word = "this is a test!";
	for (char ch : word)
	{
		letters.push(ch);
	}
	while (letters.empty() == false)
	{
		cout << letters.top();
		letters.pop();
	}
	cout << endl;

	//queues are more boring
	queue<char> letters_q{};
	for (auto ch : word)
	{
		letters_q.push(ch);
	}
	while (letters_q.empty() == false)
	{
		cout << letters_q.front();
		letters_q.pop();
	}
	cout << endl;
}

int main(int argc, char* argv[])
{
	vector<string> content{};
	stack<string> redo_stack;
	string user_input = "";
	while (user_input != "q")
	{
		for (auto word : content)
		{
			cout << word << " ";
		}
		cout << endl;
		getline(cin, user_input);
		if (user_input == "u")
		{
			string word = content[content.size() - 1];
			content.pop_back();
			redo_stack.push(word);
		}
		else if (user_input == "r")
		{
			string word = redo_stack.top();
			content.push_back(word);
			redo_stack.pop();
		}
		else
		{
			content.push_back(user_input);
		}
	}
}