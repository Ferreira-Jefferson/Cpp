#include "Contact.hpp"
#include "utils.hpp"
#include <iostream>

Contact::Contact(void) {}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds) { 
	if (!valideField(trim(fn), "First Name", false) || !valideField(trim(ln), "Last Name", false) || 
		valideField(trim(nn), "Nickname", true) || validePhoneNumber(trim(pn)) || valideField(trim(ds), "Dark Secret", true))
			return ;
	firstName = trim(fn);
	lastName = trim(ln);
	nickname = trim(nn);
	phoneNumber = trim(pn);
	darkSecret = trim(ds);
}

bool Contact::valideField(std::string field, std::string fieldName, bool allowNumber = false) const {
	if (field.empty())
	{
		std::cout << "The field [" << fieldName << "] cannot be empty." << std::endl;
		return (false);
	}
	if (!allowNumber && hasNumber(field))
	{
		std::cout << "The field [" << fieldName << "] cannot has number." << std::endl;
		return (false);
	}
	return (true);	
}

bool Contact::validePhoneNumber(std::string phoneNumber) const {
	if (!isOnlyNumber(phoneNumber))
	{
		std::cout << "The field [" << "Phone Number" << "] expects only numbers." << std::endl;
		return (false);
	}
	return (true);
}

std::string Contact::getFirstName(void) const {
	return (this->firstName);
}

bool Contact::setFirstName(std::string firstName) {
	std::string fn = trim(firstName);
	if (!this->valideField(firstName, "First Name", false))
		return false;
	this->firstName = fn;
	return true;
}

std::string Contact::getLastName(void) const {
	return (this->lastName);
}

bool Contact::setLastName(std::string lastName) {
	std::string ln = trim(lastName);
	if (!this->valideField(lastName, "Last Name", false))
		return false;
	this->lastName = ln;
	return true;
}

std::string Contact::getNickname(void) const {
	return (this->nickname);
}

bool Contact::setNickname(std::string nickname)
{
	std::string nn = trim(nickname);
	if (!this->valideField(nickname, "Nickname", true))
		return false;
	this->nickname = nn;
	return true;
}

std::string Contact::getPhoneNumber(void) const {
	return (this->phoneNumber);
}

bool Contact::setPhoneNumber(std::string phoneNumber) {
	std::string fn = trim(phoneNumber);
	if (!validePhoneNumber(phoneNumber))
		return false;
	this->phoneNumber = fn;
	return true;
}

std::string Contact::getDarkSecret(void) const {
	return (this->darkSecret);
}

bool Contact::setDarkSecret(std::string darkSecret) {
	std::string ds = trim(darkSecret);
	if (!this->valideField(darkSecret, "Dark Secret", true))
		return false;
	this->darkSecret = ds;
	return true;
}
