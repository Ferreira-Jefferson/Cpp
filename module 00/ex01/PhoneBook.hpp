#pragma once

#include "Contact.hpp"

class PhoneBook {
	private:
		Contact contacts[8];
		size_t	index = 0;
	
	public:
		PhoneBook();
		void add(Contact contact);
		void search(void);
		
}