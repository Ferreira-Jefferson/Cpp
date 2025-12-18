#pragma once

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		size_t	index;
	
		void printReport(void);
		const std::string formatText(const std::string text);
		void handlerSet(Contact& contact, bool (Contact::*fn)(std::string), std::string fieldName);
	
	public:
		PhoneBook(void);
		void add(void);
		void search(void);		
};