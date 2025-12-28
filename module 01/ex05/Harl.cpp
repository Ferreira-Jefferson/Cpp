#include "Harl.hpp"


const std::string Harl::DEBUG = "DEBUG";	
const std::string Harl::INFO = "INFO";
const std::string Harl::WARNING = "WARNING";
const std::string Harl::ERROR = "ERROR";

const std::string Harl::_level[] = {Harl::DEBUG, Harl::INFO, Harl::WARNING, Harl::ERROR};

void Harl::debug(void) {
	std::cout << "Eu amo ter bacon extra para o meu hambúrguer 7XL-duplo-queijo-triplopicles-ketchup-especial." << std::endl;
}

void Harl::info(void) {
	std::cout << "Eu não acredito que adicionar bacon extra custa mais dinheiro. \
Vocês não colocaram bacon suficiente no meu hambúrguer! Se vocês tivessem colocado, eu não estaria pedindo por mais!" << std::endl;
}

void Harl::warning(void) {
	std::cout << "Eu acho que mereço ter bacon extra de graça. Eu venho aqui há anos, \
enquanto você começou a trabalhar aqui apenas no mês passado." << std::endl;
}

void Harl::error(void) {
	std::cout << "Isto é inaceitável! Eu quero falar com o gerente agora." << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*fn[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (size_t i = 0; i < 4; i++)
		if (level == Harl::_level[i])
			(this->*fn[i])();
}