#pragma once
#include "Sorter.hpp"
#include <utility>
#include <cmath>

using namespace std;
class RadixSort : public Sorter<int>
{
public:
	virtual void sort(vector<int>& data)
	{
		vector<vector<int>> buckets{};
		vector<vector<int>> temp_buckets{};
		buckets.resize(10);
		temp_buckets.resize(10);

		int largest_magnitude = 1;
		for (int i = 0; i < data.size(); i++)
		{
			//put value into 0s bucket and also figure out 
			//# of times to loop below this FOR loop
			buckets[0].push_back(data[i]);
			int log_value = log10(data[i]) + 1;
			if (log_value > largest_magnitude)
			{
				largest_magnitude = log_value;
			}
		}

		for (int i = 0; i < largest_magnitude; i++)
		{
			int to_divide_by = pow(10, i);
			int to_mod_by = to_divide_by * 10;

			//from 0s bucket to 9s bucket, move things from buckets into
			//temp_buckets
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < buckets[i].size(); j++)
				{
					int next_bucket_index = (buckets[i][j] % to_mod_by) / to_divide_by;
					temp_buckets[next_bucket_index].push_back(buckets[i][j]);
				}
			}

			//swap temp buckets with buckets and clear temp_buckets
			swap(buckets, temp_buckets);
			temp_buckets.clear();
			temp_buckets.resize(10);
		}

		//put everything back into original data array
		int counter = 0;
		for (auto bucket : buckets)
		{
			for (auto number : bucket)
			{
				data[counter] = number;
				counter++;
			}
		}
	}
};