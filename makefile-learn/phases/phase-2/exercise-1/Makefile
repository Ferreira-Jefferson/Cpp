# NAME: nome do binário gerado pelo projeto
NAME = hello

SRC = main.cpp
# $(SRC:.cpp=.o) substitui a extensão .cpp por .o em cada item de SRC
# resultado: "main.o"
OBJ = $(SRC:.cpp=.o)

CXX = c++
# -std=c++98 força o padrão C++98 (obrigatório no 42)
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

re: fclean all

.PHONY: all clean fclean re
