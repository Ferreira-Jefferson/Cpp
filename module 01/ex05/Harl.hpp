#include <string>
#include <string_view>
#include <iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		static const std::string _level[];
	
	public:
		static const std::string DEBUG;	
		static const std::string INFO;
		static const std::string WARNING;
		static const std::string ERROR;
	
		void complain(std::string level);
};