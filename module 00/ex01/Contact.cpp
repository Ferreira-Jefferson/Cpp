#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds): 
	firstName(fn),
	lastName(ln),
	nickname(nn),
	phoneNumber(pn),
	darkSecret(ds)
	{}

bool Contact::valideField(std::string field, std::string fieldName, bool allowNumber) {
	if (field.empty())
	{
		std::cout << "The field [" << fieldName << "] cannot be empty.";
		return (false);
	}
	if (!allowNumber && hasNumber(field))
	{
		std::cout << "The field [" << fieldName << "] cannot has number.";
		return (false);
	}
	return (true);	
}

std::string Contact::getFirstName(void) {
	return (this->firstName);
}

void Contact::setFirstName(std::string firstName) {
	std::string fn = trim(firstName);
	if (!this->valideField(firstName, "First Name", false))
		return ;
	this->firstName = fn;
}


std::string Contact::getLastName(void)  {
	return (this->lastName);
}

void Contact::setLastName(std::string lastName) {
	std::string ln = trim(lastName);
	if (!this->valideField(lastName, "Last Name", false))
		return ;
	this->lastName = ln;
}

std::string Contact::getNickname(void)  {
	return (this->nickname);
}

void Contact::setNickname(std::string nickname)
{
	std::string nn = trim(nickname);
	if (!this->valideField(nickname, "Nickname", true))
		return ;
	this->nickname = nn;
}

std::string Contact::getPhoneNumber(void)  {
	return (this->phoneNumber);
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	std::string fn = trim(phoneNumber);
	if (!isOnlyNumber(phoneNumber))
	{
		std::cout << "The field [" << "Phone Number" << "] expects only numbers.";
		return ;
	}
	this->phoneNumber = fn;
}

std::string Contact::getDarkSecret(void)  {
	return (this->darkSecret);
}

void Contact::setDarkSecret(std::string darkSecret) {
	std::string ds = trim(darkSecret);
	if (!this->valideField(darkSecret, "Dark Secret", true))
		return ;
	this->darkSecret = ds;
}
