NAME = mystack
SRC = main.cpp stack.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# all: target padrão — garante que $(NAME) seja construído
all: $(NAME)

# Regra de linkagem: $(NAME) depende de todos os objetos
# Quando todos os .o estiverem prontos, este comando gera o binário final
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Pattern rule: compila cada .cpp em .o individualmente
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean: remove apenas os arquivos objeto intermediários
clean:
	rm -f $(OBJ)

# fclean: limpeza completa — primeiro chama clean, depois remove o binário
fclean: clean
	rm -f $(NAME)

# re: recompila tudo do zero — fclean apaga, all reconstrói
re: fclean all

# .PHONY: esses targets são comandos, não arquivos
# sem isso, um arquivo chamado "all" ou "clean" impediria a execução
.PHONY: all clean fclean re
