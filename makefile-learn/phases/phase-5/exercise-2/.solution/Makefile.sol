# NAME: binário gerado
NAME = convert

# SRC: arquivos fonte do projeto
SRC = main.cpp ScalarConverter.cpp
# OBJ: objetos gerados automaticamente a partir de SRC
OBJ = $(SRC:.cpp=.o)

# CXX: compilador C++
CXX = c++
# CXXFLAGS: flags padrão 42 — warnings rigorosos e padrão C++98
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# all: target padrão — constrói o binário
all: $(NAME)

# Regra de linkagem: combina todos os .o em um binário
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Pattern rule: compila cada .cpp em .o separadamente
# $< = arquivo .cpp (fonte), $@ = arquivo .o (alvo)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean: remove arquivos intermediários
clean:
	rm -f $(OBJ)

# fclean: limpeza completa — objetos e binário
fclean: clean
	rm -f $(NAME)

# re: recompilação completa do zero
re: fclean all

# .PHONY: todos os targets que não são arquivos reais
.PHONY: all clean fclean re
