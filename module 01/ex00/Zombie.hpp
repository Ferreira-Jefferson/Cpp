#include <string>

class Zombie {
	private:
		std::string _name;
	
	public:
	Zombie(std::string name);
	void announce(void);
	~Zombie(void);
};