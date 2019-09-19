#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <list> //Doubly-linked list

using namespace std;

int main(int argc, char* argv[])
{
	//2 args means 2nd arg is file name
	ifstream input_file;
	if (argc == 2)
	{
		input_file.open(argv[1]);

		if (input_file.is_open() == false)
		{
			//if not found, create file for writing later

			//DO NOT DO IN YOUR PROGRAM
			input_file.open("FirstNames.txt");
		}
	}
	else
	{
		input_file.open("FirstNames.txt");
	}
	list<string> names{};
	while (input_file.good() == true)
	{
		string line;
		getline(input_file, line);

		//adding to LL is just like adding to vector!
		names.push_back(line); 
	}

	//not allowed!
	//cout << names[10];

	//old classic C++ way (avoid)
	/*
	for (list<string>::iterator it = names.begin(); it != names.end(); it++)
	{
		cout << *it << endl;
	}
	*/

	//new easy way
	/*
	for (auto item : names)
	{
		cout << item;
	}
	*/

	string user_input;
	auto names_iterator = names.begin();
	while (user_input != "q")
	{
		//may not work on non-windows machines
		system("cls");

		//output 10 lines
		//NOTE: need to do bounds checking
		for (int i = 0; i < 10; i++)
		{
			cout << *names_iterator << endl;
			names_iterator++;
		}

		getline(cin, user_input);
		if (user_input == "a")
		{
			//do nothing as we already have advanced by 10
		}
		else if (user_input == "b")
		{
			//AC: there's got to be a better way to do this
			for (int i = 0; i < 20; i++)
			{
				names_iterator--;
			}
		}
	}
	

}