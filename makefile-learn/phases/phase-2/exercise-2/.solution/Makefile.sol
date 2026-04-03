NAME = greet
SRC = main.cpp greeter.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

# $(NAME) depende de $(OBJ): antes de linkar, todos os .o devem estar prontos
# A receita usa $(CXX) para linkar, $(OBJ) como entrada, e $@ como nome do binário
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Pattern rule: compila cada .cpp em .o individualmente
# $< = o arquivo .cpp (primeiro pré-requisito)
# $@ = o arquivo .o (o alvo)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
