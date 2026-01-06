#pragma once

#include <string>
#include <iostream>

class Animal {
	protected:
		std::string type;
	
	public:
		Animal(void);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(void);

		std::string getType(void) const; 
		virtual void makeSound(void) const;
};