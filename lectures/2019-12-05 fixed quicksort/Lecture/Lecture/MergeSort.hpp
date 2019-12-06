#pragma once
#include "Sorter.hpp"
#include <queue>
#include <utility>
using namespace std;

template <typename T>
class MergeSort : public Sorter<T>
{
private:
	vector<T> merge(vector<T>& first, vector<T>& second)
	{
		vector<T> result{};
		result.resize(first.size() + second.size());
		int first_index = 0;
		int second_index = 0;
		int result_index = 0;

		while (first_index < first.size() && second_index < second.size())
		{
			if (first[first_index] < second[second_index])
			{
				result[result_index] = first[first_index];
				first_index++;
			}
			else
			{
				result[result_index] = second[second_index];
				second_index++;
			}
			result_index++;
		}

		//when out of this loop, one of the indices are no longer good
		while (first_index < first.size())
		{
			result[result_index] = first[first_index];
			first_index++;
			result_index++;
		}

		while (second_index < second.size())
		{
			result[result_index] = second[second_index];
			second_index++;
			result_index++;
		}
		return result;

	}

public:
	virtual void sort(vector<T>& data)
	{
		//break everything into singletons
		queue<vector<T>> data_bits{};
		for (auto& item : data)
		{
			vector<T> singleton{ item };
			data_bits.push(singleton);
		}

		while (data_bits.size() > 1)
		{
			vector<T> first = data_bits.front();
			data_bits.pop();
			vector<T> second = data_bits.front();
			data_bits.pop();
			data_bits.push(merge(first, second));
		}

		//copy everything back
		data = move(data_bits.front());
	}
};