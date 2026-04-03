NAME = calc
SRC = main.cpp calc.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# %.o: %.cpp — para cada .o necessário, compila o .cpp correspondente
# A regra se aplica a qualquer arquivo: main.cpp→main.o, calc.cpp→calc.o, etc.
# $< = primeiro pré-requisito = o arquivo .cpp
# $@ = nome do alvo = o arquivo .o sendo gerado
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
