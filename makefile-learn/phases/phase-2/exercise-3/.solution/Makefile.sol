NAME = calc
SRC = main.cpp math.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean remove apenas os arquivos objeto (.o)
# Não remove o binário — isso é trabalho do fclean
clean:
	rm -f $(OBJ)

# fclean depende de clean: primeiro executa clean (remove .o),
# depois remove o binário ($(NAME))
fclean: clean
	rm -f $(NAME)

# re reconstrói tudo do zero:
# fclean apaga tudo → all recompila tudo
re: fclean all

# .PHONY garante que esses targets sempre executem,
# mesmo que existam arquivos com esses nomes na pasta
.PHONY: all clean fclean re
