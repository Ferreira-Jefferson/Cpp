#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include "utils.hpp"

PhoneBook::PhoneBook(void): index(0) {}

void printLeftAligned(const std::string& text, int width, bool pipe = false) {
	if (pipe)
		std::cout << "|";
    std::cout << std::right << std::setw(width) << text;
}

void PhoneBook::printReport(void) {
	size_t qtt = index > 8 ? 8 : index;

	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (size_t i = 0; i < qtt; i++)
	{
		std::string index_str = "N";
		index_str[0] = static_cast<char>('0' + i);
		printLeftAligned(formatText(index_str), 10);
		printLeftAligned(formatText(contacts[i].getFirstName()), 10, true);
		printLeftAligned(formatText(contacts[i].getLastName()), 10, true);
		printLeftAligned(formatText(contacts[i].getNickname()), 10, true);
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

const std::string PhoneBook::formatText(std::string text) {
	text = toLowerStr(text);
	text[0] = toupper(text[0]);
	if (text.length() > 10)
	{
		text.erase(10);
		text[9] = '.';
	}
	return (text);
}

void PhoneBook::handlerSet(Contact& contact, bool (Contact::*fn)(std::string), std::string fieldName)
{
	std::string input = "";

	std::cout << "Enter with " << fieldName << std::endl;
	while (getline(std::cin, input))
	{
		if ((contact.*fn)(input))
			break ;
	}
}

void PhoneBook::add(void) {
	Contact contact = Contact();
	
	handlerSet(contact, &Contact::setFirstName, "First Name");
	handlerSet(contact, &Contact::setLastName, "Last Name");
	handlerSet(contact, &Contact::setNickname, "Nickname");
	handlerSet(contact, &Contact::setPhoneNumber, "Phone Number");
	handlerSet(contact, &Contact::setDarkSecret, "Dark Secret");
	
	contacts[index % 8] = contact;
	index++;
}

void PhoneBook::search(void) {
	std::string index_str;
	size_t index_num;
	size_t qtt = index > 8 ? 8 : index;

	if (index == 0)
	{
		std::cout << "No contacts registered." << std::endl;
		return ;
	}
	printReport();

	while (true)
	{
		std::cout << "Enter the index of the desired contact [0-" << qtt-1 << "]." << std::endl;
		if (!getline(std::cin, index_str))
			break ;
		std::istringstream iss(index_str);
		iss >> index_num;
	
		if (index_num <= qtt-1)
		{
			std::cout << "First Name: " << contacts[index_num].getFirstName() << std::endl;
			std::cout << "Last Name: " << contacts[index_num].getLastName() << std::endl;
			std::cout << "Nickname: " << contacts[index_num].getNickname() << std::endl;
			std::cout << "Phone Number: " << contacts[index_num].getPhoneNumber() << std::endl;
			std::cout << "Dark Secret: " << contacts[index_num].getDarkSecret() << std::endl;
			std::cout << std::endl;
			break ;
		}
	}
}