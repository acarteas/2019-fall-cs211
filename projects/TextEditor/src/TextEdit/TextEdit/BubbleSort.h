#pragma once
#include "Sorter.h"

class BubbleSort : public Sorter
{
public:
	virtual void sort(vector<string>& data)
	{
		typedef vector<string>::size_type size_type;
		for (size_type i = 1; i < data.size(); ++i) // for n-1 passes
		{
			// In pass i,compare the first n-i elements
			// with their next elements
			for (size_type j = 0; j < (data.size() - 1); ++j)
			{
				if (data[j] > data[j + 1])
				{
					string const temp = data[j];
					data[j] = data[j + 1];
					data[j + 1] = temp;
				}
			}
		}
	}
};