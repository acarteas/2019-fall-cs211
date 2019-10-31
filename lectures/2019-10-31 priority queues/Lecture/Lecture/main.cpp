#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <list> //Doubly-linked list
#include <stack>
#include <queue>
#include <deque>
#include <sstream> //for istringstream
#include <unordered_map>
#include <queue> //PQs hidden in normal queue library

using namespace std;

int main(int argc, char* argv[])
{
	priority_queue<int> max_pq{};
	for (int i = 0; i < 10; i++)
	{
		max_pq.push(rand());
	}
	while (max_pq.empty() == false)
	{
		cout << max_pq.top() << endl;
		max_pq.pop();
	}

	//min PQ
	priority_queue<int, vector<int>, greater<int>> min_pq{};
	for (int i = 0; i < 10; i++)
	{
		min_pq.push(rand());
	}
	while (min_pq.empty() == false)
	{
		cout << min_pq.top() << endl;
		min_pq.pop();
	}
}