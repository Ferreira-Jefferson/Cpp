# NAME: nome do binário que será gerado
NAME = hello

# SRC: lista dos arquivos fonte .cpp
SRC = main.cpp
# OBJ: lista dos objetos — gerada automaticamente substituindo .cpp por .o
OBJ = $(SRC:.cpp=.o)

# CXX: compilador C++
CXX = c++
# CXXFLAGS: flags de compilação
# -Wall -Wextra -Werror: ativa e trata todos os warnings como erro
# -std=c++98: usa o padrão C++98
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# all: target padrão — compila o projeto
all: $(NAME)

# Regra de linkagem: gera o binário a partir dos objetos
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Pattern rule: compila cada .cpp em .o
# $< = o arquivo .cpp (fonte)
# $@ = o arquivo .o (alvo)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean: remove os arquivos objeto
clean:
	rm -f $(OBJ)

# fclean: remove objetos E o binário
# chama clean para não precisar repetir o rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)

# re: recompila tudo do zero
# fclean apaga tudo, all reconstrói
re: fclean all

# .PHONY: declara que esses targets são sempre comandos
# sem isso, se existir um arquivo chamado "clean", make não executa a receita
.PHONY: all clean fclean re
