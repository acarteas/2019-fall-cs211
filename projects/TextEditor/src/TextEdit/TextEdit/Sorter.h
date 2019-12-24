#pragma once
#include <vector>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <iterator>
#include <algorithm>
using namespace std;


class Sorter
{
public:
	virtual void sort(vector<string>& data) = 0;
	
};