#include <iostream>
#include <fstream>
#include "File.hpp"

int main(int argc, char *argv[])
{
	if (argc < 4 || argc > 4)
	{
		std::cout << "./replace <file_name> <to_replace> <replacer>" << std::endl;
		return (0);
	}
	
	if (std::string(argv[1]).empty() || std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
		std::cout << "The fields must not be empty." << std::endl;
		return (0);
	}

	std::string fileName = argv[1];
	std::string fileNameOutput = fileName + ".replace";

	std::string toReplace = argv[2];
	std::string replacer = argv[3];

	std::string content = File().read(fileName);
	size_t pos = 0;
	while (true)
	{
		pos = content.find(toReplace, pos);
		if (pos == std::string::npos)
			break ;		
		content.erase(pos, toReplace.length());
		content.insert(pos, replacer);
	}
	File().write(fileNameOutput, content);
	return (0);	
}
