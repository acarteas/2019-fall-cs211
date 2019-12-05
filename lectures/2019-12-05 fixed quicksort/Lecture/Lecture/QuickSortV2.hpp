#pragma once
#include <utility>
#include "Sorter.hpp"

/*
Ideas for helping new progammers get over variable name meaning

1. put comments in files saying "var xyz is exactly the same as calling it head"
2. Have exact same code but with different variable names
*/

using namespace std;
template <typename T>
class QuickSortV2 : public Sorter<T>
{

private:
	//assumed end_index points to last element in array, NOT size of array
	void sortHelper(vector<T>& data, int start_index, int end_index)
	{
		//array of size 1 or smaller
		if (end_index <= start_index)
		{
			return;
		}

		//array of size 2
		if (end_index - start_index == 1)
		{
			if (data[end_index] < data[start_index])
			{
				swap(data[end_index], data[start_index]);
			}
			return;
		}

		//must be size 3 or larger

		//find pivot
		T first_item = data[start_index];
		T last_item = data[end_index];
		int mid_index = (start_index + end_index) / 2;
		T middle_item = data[mid_index];
		int pivot_index = start_index;


		if (
			middle_item > first_item&& middle_item < last_item //ex: 1 5 10
			||
			middle_item < first_item && middle_item > last_item //ex: 10 5 1
			)
		{
			pivot_index = mid_index;
		}
		else if (
			last_item > first_item&& last_item < middle_item //ex: 1 10 5
			||
			last_item < first_item && last_item > middle_item //ex: 10 1 5
			)
		{
			pivot_index = end_index;
		}

		//swap pivot with end index
		T pivot_value = data[pivot_index];
		swap(data[pivot_index], data[end_index]);

		/*
		1. Define i = front_index; j = end_index - 1;
		2. While data[i] < pivot AND i < j
		a. i++
		3. While data[j] > pivot and i < j
		a. j--
		4. if i != j
		a. Swap(data[i], data[j])
		b. GOTO #2
		*/
		int i = start_index;
		int j = end_index - 1;
		while (i < j)
		{
			while (data[i] < pivot_value && i < j)
			{
				i++;
			}
			while (data[j] >= pivot_value && i < j)
			{
				j--;
			}
			if (i < j)
			{
				swap(data[i], data[j]);
			}
		}

		//swap pivot back
		swap(data[i], data[end_index]);

		//recursively repeat
		sortHelper(data, start_index, i - 1);
		sortHelper(data, i + 1, end_index);
	}

public:
	virtual void sort(vector<T>& data)
	{
		sortHelper(data, 0, data.size() - 1);
	}
};