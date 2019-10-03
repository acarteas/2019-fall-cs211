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

using namespace std;

//Task #1: Count # of distinct words in a string
//O(N)
int calculateDistinctWords_ht(string text)
{
	//            KEY,    VALUE
	unordered_map<string, int> words{};
	istringstream buffer{ text };

	//O(N)
	while (buffer.good() == true)
	{
		string next_word;
		buffer >> next_word;

		//O(1)
		words[next_word] = 1;
	}
	return words.size();
}

//worst case O(N^2); N = length of text
int calculateDistinctWords_vector(string text)
{
	vector<string> words{};
	istringstream buffer{ text };

	//for as many words there are in the string
	//(up to 1/2 length of text)
	while (buffer.good() == true)
	{
		string next_word;
		buffer >> next_word;
		bool found = false;

		//up to # of words in text (1/2 length of text)
		for (auto& word : words)
		{
			if (next_word == word)
			{
				found = true;
				break;
			}
		}
		if (found == false)
		{
			words.push_back(next_word);
		}
	}
	return words.size();
}

unordered_map<char, int> getFrequencyDistribution(string text)
{
	//            KEY,    VALUE
	unordered_map<char, int> characters{};
	istringstream buffer{ text };

	//O(N)
	while (buffer.good() == true)
	{
		string next_word;
		buffer >> next_word;
		for (auto ch : next_word)
		{
			characters[ch]++;
		}
	}
	return characters;
}

//Task #2: Calculate average rainfall
void populate_rainfall()
{
	vector<string> years = { "2017", "2018", "2019" };
	vector<string> data{};

	//make up a bunch of data to save to file
	ofstream output_file{ "data.csv" };
	for (int i = 0; i < 10000; i++)
	{
		int random_year = rand() % 3;
		int random_month = rand() % 12 + 1;
		int random_day = rand() % 31 + 1;
		int random_rainfall = rand() % 5;

		output_file << years[random_year];
		output_file << "-" << random_month;
		output_file << "-" << random_day;
		output_file << "," << random_rainfall;
		output_file << endl;
	}
	output_file.close();
}
string calculateRainfall()
{
	//what day and month received the most rainfall?
	unordered_map<string, int> data{};
	ifstream data_file{ "data.csv" };
	while (data_file.good() == true)
	{
		string date;
		int rainfall;
		getline(data_file, date, ',');
		data_file >> rainfall;

		istringstream date_pieces{ date };
		string year;
		string month;
		string day;
		getline(date_pieces, year, '-');
		getline(date_pieces, month, '-');
		getline(date_pieces, day);

		ostringstream formatted_date{};
		formatted_date << month << "-" << day;
		data[formatted_date.str()] += rainfall;
	}

	//once we go through all of our data, figure out which
	//has most rain

	//default key will be first in the HT
	string key_with_most_rain = data.begin()->first;

	//the above is shorthand for this...
	key_with_most_rain = (*data.begin()).first;
	for (auto item : data)
	{
		if (data[key_with_most_rain] < item.second)
		{
			key_with_most_rain = item.first;
		}
	}
	return key_with_most_rain;
}

int main(int argc, char* argv[])
{
	string text = "this is a test i can't use periods ";
	text += " or punctuation but it still is a basic representation " +
		text += "of word counting";
	int num_words = calculateDistinctWords_vector(text);
	num_words = calculateDistinctWords_ht(text);
	auto chars = getFrequencyDistribution(text);

	//output distribution to the screen (not sorted)
	for (auto item : chars)
	{
		//item is a key-value-pair object
		//item.first -> key
		//item.second -> value
		cout << "[" << item.first << "]: " << item.second << endl;
	}

	//to output in sorted order, we need to use a C++ STL map
	//or maintain a list of separate keys
	vector<char> keys{};

	//copy HT's keys to vector
	for (auto item : chars)
	{
		keys.push_back(item.first);
	}
	sort(keys.begin(), keys.end());
	for (auto key : keys)
	{
		cout << "[" << key << "]: " << chars[key] << endl;
	}

	cout << "day with most rain: " << calculateRainfall() << endl;
}