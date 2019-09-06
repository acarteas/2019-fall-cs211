#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
	cout << "Argument output: " << endl;
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
}