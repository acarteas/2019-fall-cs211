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
	SortingBenchmark bm{};

	unordered_map<string, Sorter<int>*> sorting_algorithms{};
	//sorting_algorithms["Insertion Sort"] = new InsertionSort<int>{};
	//sorting_algorithms["Selection Sort"] = new SelectionSort<int>{};
	sorting_algorithms["Merge Sort"] = new MergeSort<int>{};
	sorting_algorithms["Quick Sort"] = new QuickSort<int>{};
	sorting_algorithms["Quick Sort V2"] = new QuickSortV2<int>{};
	sorting_algorithms["Radix Sort"] = new RadixSort{};
	
	/*
	auto glambda = [](
		SortingBenchmark& bm, 
		Sorter<int>* sorter,
		vector<int>& data, 
		int count) { 
			bm.sortBenchmark(sorter, &data, count); 
				};
	
	unordered_map<string, typeof(glambda)> benchmarks{};
	*/
	ofstream output_file{ "results.csv" };
	

	//empty cell for vector size below
	output_file << " ,";
	for (auto algorithm : sorting_algorithms)
	{
		output_file << algorithm.first << " random,";
		output_file << algorithm.first << " sorted,";
		output_file << algorithm.first << " reversed,";
	}
	output_file << endl;
	for (int i = 5000; i < 50000; i += 5000)
	{
		cout << i << endl;
		output_file << i << ",";
		for (auto algorithm : sorting_algorithms)
		{
			numbers.clear();
			auto result = bm.sortBenchmark(algorithm.second, &numbers, i);
			output_file << result << ",";

			numbers.clear();
			result = bm.sortPreSortedBenchmark(algorithm.second, &numbers, i);
			output_file << result << ",";

			numbers.clear();
			result = bm.sortReverseSortedBenchmark(algorithm.second, &numbers, i);
			output_file << result << ",";
		}
		output_file << endl;
	}

	output_file.close();
}