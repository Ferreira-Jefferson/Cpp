#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other)
{
	if (this != &other)
		_db = other._db;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void BitcoinExchange::loadDatabase(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open database file.");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type comma = line.find(',');
		if (comma == std::string::npos)
			continue;
		std::string date = line.substr(0, comma);
		float rate = std::atof(line.substr(comma + 1).c_str());
		_db[date] = rate;
	}
}

bool BitcoinExchange::isValidDate(std::string const &date) const
{
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
		return false;
	return true;
}

float BitcoinExchange::getRate(std::string const &date) const
{
	std::map<std::string, float>::const_iterator it = _db.lower_bound(date);
	if (it != _db.end() && it->first == date)
		return it->second;
	if (it == _db.begin())
		return it->second;
	--it;
	return it->second;
}

void BitcoinExchange::processInput(std::string const &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("could not open file.");

	std::string line;
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::string::size_type sep = line.find(" | ");
		if (sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, sep);
		std::string valueStr = line.substr(sep + 3);

		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}

		char *end;
		double value = std::strtod(valueStr.c_str(), &end);
		if (*end != '\0' || valueStr.empty())
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (value > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue;
		}

		float rate = getRate(date);
		std::cout << date << " => " << value << " = " << value * rate << std::endl;
	}
}
