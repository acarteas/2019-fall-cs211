#pragma once
#ifndef SORTING_BENCHMARK_H
#define SORTING_BENCHMARK_H

#include <chrono>
#include "Sorts.hpp"
using namespace std;
using namespace std;
using namespace std::chrono;
class SortingBenchmark
{
public:

	SortingBenchmark()
	{
		srand(time(NULL));
	}

	long long emptyBenchmark(Sorter<int>* sort, vector<int>* data)
	{
		//setup our stopwatches
		system_clock::time_point start;
		system_clock::time_point end;

		//TODO: any pre-setup

		//begin benchmark
		start = system_clock::now();

		//TODO: benchmark

		//stop timer
		end = system_clock::now();

		//return duration in milliseconds
		return duration_cast<milliseconds>(end - start).count();
	}

	long long sortBenchmark(Sorter<int>* sort, vector<int>* data, int num_trials)
	{
		//setup our stopwatches
		system_clock::time_point start;
		system_clock::time_point end;

		//TODO: any pre-setup
		for (int i = 0; i < num_trials; i++)
		{
			data->push_back(rand());
		}

		//begin benchmark
		start = system_clock::now();

		//TODO: benchmark
		sort->sort(*data);

		//stop timer
		end = system_clock::now();

		//return duration in milliseconds
		return duration_cast<milliseconds>(end - start).count();
	}

	long long sortPreSortedBenchmark(Sorter<int>* sort, vector<int>* data, int num_trials)
	{
		//setup our stopwatches
		system_clock::time_point start;
		system_clock::time_point end;

		//TODO: any pre-setup
		for (int i = 0; i < num_trials; i++)
		{
			data->push_back(i);
		}

		//begin benchmark
		start = system_clock::now();

		//TODO: benchmark
		sort->sort(*data);

		//stop timer
		end = system_clock::now();

		//return duration in milliseconds
		return duration_cast<milliseconds>(end - start).count();
	}

	long long sortReverseSortedBenchmark(Sorter<int>* sort, vector<int>* data, int num_trials)
	{
		//setup our stopwatches
		system_clock::time_point start;
		system_clock::time_point end;

		//TODO: any pre-setup
		for (int i = 0; i < num_trials; i++)
		{
			data->push_back(num_trials - i);
		}

		//begin benchmark
		start = system_clock::now();

		//TODO: benchmark
		sort->sort(*data);

		//stop timer
		end = system_clock::now();

		//return duration in milliseconds
		return duration_cast<milliseconds>(end - start).count();
	}

};

#endif // !QUEUE_BENCHMARK_H
