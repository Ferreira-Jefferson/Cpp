#include <iostream>

int main(void) {
	std::string base = "HI THIS IS BRAIN";
	std::string test = "HI THIS NOT IS BRAIN";
	std::string *stringPTR = &base;
	std::string &stringREF = base;

	std::cout << "Adress base:      " << &base << std::endl;
	std::cout << "Adress stringPTR: " << stringPTR << std::endl;
	std::cout << "Adress stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value base:      " << base << std::endl;
	std::cout << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value stringREF: " << stringREF << std::endl;

	stringPTR = &test;
	stringREF = test;

	std::cout << std::endl;
	
	std::cout << "Adress base:      " << &base << std::endl;
	std::cout << "Adress test:      " << &test << std::endl;
	std::cout << "Adress stringPTR: " << stringPTR << std::endl;
	std::cout << "Adress stringREF: " << &stringREF << std::endl;

	test = "HI THIS NOT IS OTHER BRAIN";

	std::cout << std::endl;

	std::cout << "Value base:      " << base << std::endl;
	std::cout << "Value test:      " << test << std::endl;
	std::cout << "Value stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value stringREF: " << stringREF << std::endl;


	return (0);
}