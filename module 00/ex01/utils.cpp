#include "utils.hpp"
#include <iostream>
#include <cctype>
#include <string>

void ft_print(const std::string& content, const std::string end = "\n")
{
	std::cout << content << end;
}

std::string trim(std::string str) {
	size_t i = 0;
	size_t j = str.length() - 1;

	if (str.empty())
		return (str);
	while (isspace(static_cast<unsigned char>(str[i])) || isspace(static_cast<unsigned char>(str[j])))
	{
		if (isspace(static_cast<unsigned char>(str[i])))
			i++;
		if (isspace(static_cast<unsigned char>(str[j])))
			j--;	
	}
	str.erase(j + 1);
	str.erase(0, i);
	return (str);
}

bool hasNumber(std::string str)
{
	for (std::string::iterator c = str.begin(); c != str.end(); c++)
		if (isdigit(static_cast<unsigned char>(*c)))
			return (true);
	return (false);

}

bool isOnlyNumber(std::string str)
{
	for (std::string::iterator c = str.begin(); c != str.end(); c++)
		if (!isdigit(static_cast<unsigned char>(*c)))
			return (false);
	return (true);
}

std::string toLowerStr(const std::string& s) {
	std::string result = s;
	for (size_t i = 0; i < result.size(); ++i) {
		result[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(result[i])));
	}
	return result;
}