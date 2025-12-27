#include "File.hpp"

void File::open(std::fstream& file, std::string fileName, std::ios::openmode mode)
{
	file.open(fileName.c_str(), mode);
	if (file.fail()) 
		std::cout << fileName << " Error: The file could not be opened." << std::endl;
}

std::string File::read(std::string fileName)
{
	std::string line;
	std::stringstream content;
	std::fstream inFile;
	open(inFile, fileName, std::ios::in);

	if (inFile)
	{
		while (getline(inFile, line))
			content << line << std::endl;
		inFile.close();
	}
	return (content.str());
}

void File::write(std::string fileName, std::string& content)
{
	std::fstream outFile;
	open(outFile, fileName, std::ios::out);

	if (outFile)
	{
		outFile.write(content.c_str(), content.length());
		outFile.close();
	}
}

void close(std::fstream file)
{
	if (file)
		file.close();
}