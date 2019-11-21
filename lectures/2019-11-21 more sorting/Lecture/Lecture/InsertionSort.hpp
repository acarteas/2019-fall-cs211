#pragma once
#include "Sorter.hpp"

template <typename T>
class InsertionSort : public Sorter<T>
{
public:
	virtual void sort(vector<T>& data)
	{
		for (int i = 1; i < data.size(); i++)
		{
			for (int j = i; j > 0; j--)
			{
				if (data[j] < data[j - 1])
				{
					T temp = data[j];
					data[j] = data[j - 1];
					data[j - 1] = temp;
				}
				else
				{
					//in correct position relative to
					//sorted set of list

					//This extra check ensures O(N) on sorted
					//data
					break;
				}
			}
		}
	}
};