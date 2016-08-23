#include "File.h"
#include <iostream>
#include <fstream>

using namespace std;

bool File::readAllContent(const std::string & path, std::string * content)
{
	ifstream file(path);
	if (!file.good())
	{
		*content = "";
		return false;
	}

	*content = string(istreambuf_iterator<char>(file), istreambuf_iterator<char>());
	return true;
}
