#include <iostream>
#include <cctype>
#include <string>

void ft_print(const std::string& content, bool hasEndl)
{
	std::cout << content;
	if (hasEndl)
		std::cout << std::endl;
}

std::string megaphone(std::string text)
{
	std::string text_upper = "";

	for(std::string::iterator c = text.begin(); c != text.end(); c++)
		text_upper += static_cast<char>(toupper(static_cast<unsigned char>(*c)));
	return (text_upper);
}

int main(int argc, char *argv[])
{
	std::string default_message = "* loud and unbearable feedback noise *";
	
	if (argc == 1)
		ft_print(megaphone(default_message), true);
	else
	{
		for (int i=1; i < argc; i++)
			ft_print(megaphone(argv[i]), false);
		ft_print("", true);		
	}
	return (0);
}