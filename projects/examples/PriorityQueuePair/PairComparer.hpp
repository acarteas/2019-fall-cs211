#include <iostream>
#include <queue>
#include <string>
using namespace std;

class MaxHeapPairComparer
{
public:
	template<typename K, typename V> 
	bool operator()(const pair<K, V>& left, const pair <K, V>& right)
	{
		return left.second < right.second;
	}
};

class MinHeapPairComparer
{

public:
	template<typename K, typename V>
	bool operator()(const pair<K, V>& left, const pair <K, V>& right)
	{
		return left.second > right.second;
	}
};