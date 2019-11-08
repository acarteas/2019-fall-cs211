#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include "PairComparer.hpp"
using namespace std;

int main(void)
{
	priority_queue< pair<string, int>, vector<pair<string, int>>, MaxHeapPairComparer> max_pq{};

	max_pq.push(make_pair("a", 3));
	max_pq.push(make_pair("z", 1));
	max_pq.push(make_pair("b", 4));
	max_pq.push(make_pair("e", 7));
	while (max_pq.empty() == false)
	{
		cout << max_pq.top().first << endl;
		max_pq.pop();
	}
}