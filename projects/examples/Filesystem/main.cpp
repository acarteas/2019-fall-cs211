#include <filesystem>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

//see https://stackoverflow.com/questions/50668814/vs2017-e0135-namespace-std-has-no-member-filesystem
//for forcing C++ 17 in VS 2019
namespace fs = std::filesystem;

int main(void)
{
	fs::path current_path{ fs::current_path() };

	wostringstream wos;
	int i = 0;

	string user_input = "";
	while (user_input != "q")
	{
		//list files
		vector<string> current_directories{};

		cout << "Your are in: " << current_path << endl;
		cout << "Files in this location: " << endl;
		for (auto item : fs::directory_iterator(current_path))
		{
			if (fs::is_directory(item.path()) == true)
			{
				current_directories.push_back(item.path().filename().string());
				cout << "[D] ";
			}
			cout << item.path().filename() << endl;
		}

		//prompt for selection
		cout << "selection: " << endl;
		getline(cin, user_input);

		if (user_input == "..")
		{
			//go up one directory
			current_path = current_path.parent_path();
		}
		else if (user_input != "q")
		{
			if (find(current_directories.begin(), current_directories.end(), user_input) != current_directories.end())
			{
				current_path.append(user_input);
			}
		}
	}
	
	
}