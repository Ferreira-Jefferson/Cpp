#pragma once

#include <string>
#include <fstream>
#include <iostream>

class File {
	public:
		static bool error;
		std::string read(std::string fileName);
		void write(std::string fileName, std::string& content);
};