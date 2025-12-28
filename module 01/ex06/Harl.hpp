#include <string>
#include <string_view>
#include <iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		enum _eLevel { DEBUG, INFO, WARNING, ERROR };
		int getLevel(std::string level);
	
	public:
		void complain(std::string level);
};