#include <string>

class Zombie {
	private:
		std::string _name;
	
	public:
	Zombie(void);
	void setName(std::string name);
	void announce(void);
	~Zombie(void);
};