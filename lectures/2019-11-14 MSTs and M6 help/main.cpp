#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include "sorting\Sorting.h"
#include "benchmarks\SortingBenchmark.h"
#include "ADTs\Vector.h"
#include "ADTs\StringGraphNode.h"

using namespace std;

bool isConnectedHelper(
	StringGraphNode* node,
	string destination,
	unordered_map<string, int> visited_map
)
{
	if (node == nullptr)
	{
		//null node means not connected, so return false
		return false;
	}

	if (node->getKey() == destination)
	{
		return true;
	}

	//mark as visited
	visited_map[node->getKey()]++;

	//if we've gotten this far, we need to visit all of our
	//children
	for (auto node : node->getEdges())
	{
		//check node if not seen before
		if (visited_map.find(node->getKey()) == visited_map.end())
		{
			bool found = isConnectedHelper(
				dynamic_cast<StringGraphNode*>(node),
				destination,
				visited_map
			);
			if (found == true)
			{
				return true;
			}
		}
		else
		{
			//back edge
		}
	}
	return false;
}

bool isConnected(StringGraphNode* start, string destination)
{
	unordered_map<string, int> found_map{};
	return isConnectedHelper(start, destination, found_map);
}

bool isConnectedBfs(StringGraphNode* start, string destination)
{
	queue<StringGraphNode*> to_visit{};
	unordered_map<string, int> visited{};
	to_visit.push(start);
	while (to_visit.empty() == false)
	{

		//grab next node
		StringGraphNode* next = to_visit.front();
		to_visit.pop();

		//if not seen, process
		if (visited[next->getKey()] == 0)
		{
			visited[next->getKey()]++;

			for (auto node : next->getEdges())
			{
				if (node->getKey() == destination)
				{
					return true;
				}
				to_visit.push(dynamic_cast<StringGraphNode*>(node));
			}
		}
	}
	return false;
}

string intToBinary(int some_number)
{
	//below code doesn't work for zero
	if (some_number == 0)
	{
		return "0";
	}

	stack<uint8_t> bits{};
	while (some_number > 0)
	{
		bits.push(some_number & 1);
		some_number = some_number >> 1;
	}
	ostringstream result;
	while (bits.empty() == false)
	{
		result << (short)bits.top();
		bits.pop();
	}
	return result.str();
}

int main(void)
{
	//maintains full collection of all vertices
	unordered_map<string, StringGraphNode*> graph{};

	//add vertices to graph
	graph["A"] = new StringGraphNode{ "A" };
	graph["B"] = new StringGraphNode{ "B" };
	graph["C"] = new StringGraphNode{ "C" };
	graph["D"] = new StringGraphNode{ "D" };
	graph["E"] = new StringGraphNode{ "E" };
	graph["F"] = new StringGraphNode{ "F" };

	//A is connected to B and F
	graph["A"]->addEdge(graph["B"]);
	graph["A"]->addEdge(graph["F"]);

	//B is connected to A, C, and F
	graph["B"]->addEdge(graph["A"]);
	graph["B"]->addEdge(graph["C"]);
	graph["B"]->addEdge(graph["F"]);

	//connect E to F and F to E
	graph["E"]->addEdge(graph["F"]);
	graph["F"]->addEdge(graph["E"]);

	cout << intToBinary(26);
	return 0;
}