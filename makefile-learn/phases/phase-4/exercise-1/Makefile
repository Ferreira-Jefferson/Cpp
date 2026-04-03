NAME = calc
SRC = main.cpp calc.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# ESCREVA AQUI: regra que compila cada .cpp em .o
# Requisitos:
#   - Use pattern rule com %.o e %.cpp
#   - Use variável automática $< para o fonte (.cpp)
#   - Use variável automática $@ para o alvo (.o)
#   - Use $(CXX) $(CXXFLAGS) com a flag -c

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
