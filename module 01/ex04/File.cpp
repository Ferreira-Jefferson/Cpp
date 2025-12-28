#include "File.hpp"

bool File::error = false;

std::string File::read(std::string fileName)
{
	File::error = false;
	std::string content;
	std::ifstream inFile(fileName.c_str());
	if (inFile.fail())
	{
		std::cout << "Error: The file [" << fileName << "] could not be opened." << std::endl;
		File::error = true;
		return (content);
	}

	char c;
	while (inFile >> std::noskipws >> c)
		content.push_back(c);

	inFile.close();
	return (content);
}

void File::write(std::string fileName, std::string& content)
{
	if (File::error)
		return ;
	std::ofstream outFile(fileName.c_str());
	if (outFile.fail())
	{
		std::cout << "Error: The file [" << fileName << "] could not be opened." << std::endl;
		File::error = true;
		return ;
	}

	outFile.write(content.c_str(), content.length());
	outFile.close();
}
