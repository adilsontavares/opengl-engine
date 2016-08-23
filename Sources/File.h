#pragma once
#include <iostream>

class File
{
private:
	
	File();
	~File();

public:

	static bool readAllContent(const std::string & path, std::string *content);
};

