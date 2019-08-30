#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;
vector<string> readFile(ifstream& input_file);
vector<string> readFile(const string& file_name);
string toTitleCase(const string& input);

int main(void)
{
	//read FirstNames.txt and LastNames.txt into two vectors,
	//randomly output a full name
	vector<string> first_names = readFile("FirstNames.txt");
	vector<string> last_names = readFile("LastNames.txt");

	srand(time(NULL));
	string random_first = first_names[rand() % first_names.size()];
	string random_last = last_names[rand() % last_names.size()];

	random_first = toTitleCase(random_first);
	random_last = toTitleCase(random_last);
	cout << random_first << " " << random_last << endl;
}

vector<string> readFile(ifstream& input_file)
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

vector<string> readFile(const string& file_name)
{
	ifstream input_file{ file_name };
	vector<string> data = readFile(input_file);
	input_file.close();
	return data;
}

string toTitleCase(const string& input)
{
	//make sure input size is > 0
	if (input.length() == 0)
	{
		return "";
	}

	//make first char upper
	string result = input;
	result[0] = toupper(result[0]);
	transform(
		result.begin() + 1,
		result.end(),
		result.begin() + 1,
		::tolower
	);
	return result;
}