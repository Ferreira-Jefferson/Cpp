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

# ESCREVA AQUI: targets clean, fclean, re e .PHONY
# clean  → remove os arquivos .o
# fclean → chama clean E remove o binário
# re     → chama fclean e depois all
# .PHONY → declara que todos os targets acima são sempre comandos
