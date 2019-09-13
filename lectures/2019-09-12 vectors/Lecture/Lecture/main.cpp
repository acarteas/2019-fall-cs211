#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Vector.hpp"

using namespace std;

void printVector(Vector<int>& data)
{
	for (int i = 0; i < data.size(); i++)
	{
		cout << data[i] << endl;
	}
}

void print2Darray(Vector < Vector<int>> &data)
{
	for (int i = 0; i < data.size(); i++)
	{
		for (int j = 0; j < data[i].size(); j++)
		{
			cout << data[i][j] << endl;
		}
	}
}

int main(int argc, char* argv[])
{
	vector<int> numbers{1, 2, 3, 4, 5};
	Vector<int> numbers1{};

	//copy constructor - numbers2 does not exist yet;
	//Vector<int> numbers2{ numbers1 };

	//copy operator = numbers3 is created and then assigned value
	//of numbers 2
	Vector<int> numbers3{};
	//numbers3 = numbers2;

	for (int i = 0; i < 20; i++)
	{
		numbers1 >> i;
	}
	//printVector(numbers1);

	Vector < Vector<int>> two_d_array{};
	for (int i = 0; i < 4; i++)
	{
		two_d_array.push_back(Vector<int>{});
		for (int j = 0; j < 4; j++)
		{
			two_d_array[i].push_back(i * j);
		}
	}
	print2Darray(two_d_array);
}