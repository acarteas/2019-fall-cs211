#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{
	//read FirstNames.txt and LastNames.txt into two vectors,
	//randomly output a full name
	vector<string> first_names{};
	vector<string> last_names{};

	ifstream input_file{ "FirstNames.txt" };
	if (input_file.is_open() == true)
	{
		//.good() is like a better .eof
		while (input_file.good() == true)
		{
			string line;

			//       FROM        TO
			getline(input_file, line);
			first_names.push_back(line);
		}
	}
}