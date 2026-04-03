NAME = counter
SRC = main.cpp counter.cpp
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

# BUG CORRIGIDO: fclean precisa depender de clean para remover os .o também
# Sem "clean" como dependência, os arquivos .o ficam no diretório após fclean
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
