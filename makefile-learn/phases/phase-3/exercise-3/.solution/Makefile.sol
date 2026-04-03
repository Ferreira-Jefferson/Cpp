NAME = logger
SRC = main.cpp logger.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

# BUG 1 CORRIGIDO: re deve depender de fclean (não de clean)
# "re: clean all" remove só os .o mas não o binário,
# então "all" vê o binário existente e diz "Nothing to be done"
re: fclean all

# BUG 2 CORRIGIDO: .PHONY adicionado
# Sem .PHONY, se existir um arquivo chamado "all" na pasta,
# "make all" para de funcionar (considera o arquivo como alvo atualizado)
.PHONY: all clean fclean re
