#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();

		void loadDatabase(std::string const &filename);
		void processInput(std::string const &filename);

	private:
		std::map<std::string, float> _db;

		float getRate(std::string const &date) const;
		bool isValidDate(std::string const &date) const;
};
