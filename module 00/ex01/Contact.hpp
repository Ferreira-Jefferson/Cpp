#pragma once

#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickname;
		std::string phoneNumber;
		std::string darkSecret;
		bool valideField(std::string str, std::string field, bool allowNumber);

	public:
		Contact(std::string firstName, std::string lastName, std::string nickname, 
			std::string phoneNumber, std::string darkSecret);

		std::string getFirstName(void);
		void setFirstName(std::string firstName);

		std::string getLastName(void);
		void setLastName(std::string lastName);

		std::string getNickname(void);
		void setNickname(std::string nickname);

		std::string getPhoneNumber(void);
		void setPhoneNumber(std::string phoneNumber);

		std::string getDarkSecret(void);
		void setDarkSecret(std::string darkSecret);
};