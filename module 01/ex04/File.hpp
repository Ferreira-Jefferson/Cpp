#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class File {
	private:
		void open(std::fstream& file, std::string fileName, std::ios_base::openmode mode);
		void close(std::fstream file);

	public:
		std::string read(std::string fileName);
		void write(std::string fileName, std::string& content);
};