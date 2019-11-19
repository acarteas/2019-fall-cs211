#pragma once
#include <vector>
using std::vector;

template <typename T>
class Sorter
{
public:
	virtual void sort(vector<T>& data) = 0;
};