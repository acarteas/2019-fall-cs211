#pragma once
#include "Sorter.h"

class SelectionSort : public Sorter
{
public:
	virtual void sort(vector<string>& data)
	{
		
		for (int j = 0; j < data.size() - 1; ++j)
		{
			int min = j;
			for (int i = j + 1; i < data.size(); ++i)
			{
				if (data.at(min) > data.at(i)) {
					min = i;
				}
			}
			if (min != j)
			{
				//swap(data.at(j), data.at(min));
				string temp = data.at(j);
				data.at(j) = data.at(min);
				data.at(min) = temp;
			}
				
		}
	}
};