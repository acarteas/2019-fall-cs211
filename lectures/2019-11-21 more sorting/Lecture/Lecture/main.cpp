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
#include "Sorts.hpp"
#include "SortingBenchmark.hpp"


using namespace std;


int main(int argc, char* argv[])
{
	vector<int> numbers{};
	for (int i = 0; i < 100; i++)
	{
		numbers.push_back(rand());
	}

	unordered_map<string, Sorter<int>*> sorting_algorithms{};
	sorting_algorithms["Insertion Sort"] = new InsertionSort<int>{};
	sorting_algorithms["Selection Sort"] = new SelectionSort<int>{};
	sorting_algorithms["Bubble Sort"] = new BubbleSort<int>{};
	
}