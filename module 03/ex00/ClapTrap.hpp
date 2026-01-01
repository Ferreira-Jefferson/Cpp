#include <string>

class ClapTrap {
	private:
		std::string _name;
		int _hitPoint;
		int _energyPoint;
		int _attackDamage;

	public:
		ClapTrap(void);
		ClapTrap(const ClapTrap& other);
		ClapTrap& operator=(const ClapTrap& other);
		~ClapTrap(void);

		ClapTrap(std::string name);

		std::string getName(void) const;
		int getHitPoint(void) const;
		int getEnergyPoint(void) const;
		int getAttackDamage(void) const;

		void setName(std::string name);
		void setHitPoint(int v);
		void setEnergyPoint(int v);
		void setAttackDamage(int v);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};