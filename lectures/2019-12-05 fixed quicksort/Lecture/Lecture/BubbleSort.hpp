#pragma once
#include "Sorter.hpp"

template <typename T>
class BubbleSort : public Sorter<T>
{
public:
	virtual void sort(vector<T>& data)
	{
		for (int i = 0; i < data.size(); i++)
		{
			bool has_swapped = false;
			for (int j = 1; j < data.size() - i; j++)
			{
				if (data[j - 1] > data[j])
				{
					T temp = data[j - 1];
					data[j - 1] = data[j];
					data[j] = temp;
					has_swapped = true;
				}
			}
			if (has_swapped == false)
			{
				//data is sortd, break out of loop
				break;
			}
		}
	}
};