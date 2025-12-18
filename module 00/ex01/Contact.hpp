#pragma once

#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkSecret;
		bool valideField(std::string str, std::string field, bool allowNumber) const;
		bool validePhoneNumber(std::string str) const;

	public:
		Contact(void);
		Contact(std::string firstName, std::string lastName, std::string nickname, 
			std::string phoneNumber, std::string darkSecret);

		std::string getFirstName(void) const;
		bool setFirstName(std::string firstName);

		std::string getLastName(void) const;
		bool setLastName(std::string lastName);

		std::string getNickname(void) const;
		bool setNickname(std::string nickname);

		std::string getPhoneNumber(void) const;
		bool setPhoneNumber(std::string phoneNumber);

		std::string getDarkSecret(void) const;
		bool setDarkSecret(std::string darkSecret);
};