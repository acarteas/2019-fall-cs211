#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
vector<string> readFile(ifstream input_file);

int main(void)
{
	//read FirstNames.txt and LastNames.txt into two vectors,
	//randomly output a full name
	vector<string> first_names{};
	vector<string> last_names{};

	ifstream input_file{ "FirstNames.txt" };
	first_names = readFile(input_file);
}

vector<string> readFile(ifstream input_file)
{
	vector<string> lines{};
	if (input_file.is_open() == true)
	{
		//.good() is like a better .eof
		while (input_file.good() == true)
		{
			string line;

			//       FROM        TO
			getline(input_file, line);
			lines.push_back(line);
		}
	}
	return lines;
}