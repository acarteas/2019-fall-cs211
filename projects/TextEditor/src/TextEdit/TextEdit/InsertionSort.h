#pragma once
#include "Sorter.h"

class InsertionSort : public Sorter
{
public:
	virtual void sort(vector<string>& data)
	{
		for (auto it = data.begin(); it != data.end(); it++)
		{
			// Searching the upper bound, i.e., first  
			// element greater than *it from beginning 
			auto const insertion_point = upper_bound(data.begin(), it, *it);

			// Shifting the unsorted part 
			rotate(insertion_point, it, it + 1);
		}
	}
};