#include <iostream>
#include <fstream>
#include "File.hpp"

std::string replace(std::string& toReplace, std::string& replacer, std::string content);

int main(int argc, char *argv[])
{
	if (argc < 4 || argc > 4)
	{
		std::cout << "Expected: ./replace <file_name> <to_replace> <replacer>" << std::endl;
		return (0);
	}
	
	if (std::string(argv[1]).empty() || std::string(argv[2]).empty())
	{
		std::cout << "The fields <file_name> and <to_replace> must not be empty." << std::endl;
		return (0);
	}

	std::string fileName = argv[1];
	std::string toReplace = argv[2];
	std::string replacer = argv[3];

	std::string content = File().read(fileName);
	if (File::error)
		return (0);
	content = replace(toReplace, replacer, content);

	std::string fileNameOutput = fileName + ".replace";
	File().write(fileNameOutput, content);
	return (0);	
}
