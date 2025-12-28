#include "Harl.hpp"

void Harl::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "Eu amo ter bacon extra para o meu hambúrguer 7XL-duplo-queijo-triplopicles-ketchup-especial." << std::endl;
	std::cout << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "Eu não acredito que adicionar bacon extra custa mais dinheiro. \
Vocês não colocaram bacon suficiente no meu hambúrguer! Se vocês tivessem colocado, eu não estaria pedindo por mais!" << std::endl;
	std::cout << std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "Eu acho que mereço ter bacon extra de graça." << std::endl
	<< "Eu venho aqui há anos, enquanto você começou a trabalhar aqui apenas no mês passado." << std::endl;
	std::cout << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "Isto é inaceitável! Eu quero falar com o gerente agora." << std::endl;
	std::cout << std::endl;
}

int Harl::getLevel(std::string level) {
	std::string levelNames[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	
	for (int i = 0; i < 4; i++)
		if (level == levelNames[i])
			return (i);
	return (-1);
}

void Harl::complain(std::string level) {
	int index = getLevel(level);

	switch (index)
	{
		case DEBUG: this->debug();
		case INFO: this->info();
		case WARNING: this->warning();
		case ERROR: this->error();
			break;		
		default:
			std::cout << "[ Provavelmente reclamando sobre problemas insignificantes ]" << std::endl;
			break;
	}
}