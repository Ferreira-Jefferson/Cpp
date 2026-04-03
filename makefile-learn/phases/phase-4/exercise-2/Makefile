NAME = mystack
SRC = main.cpp stack.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

# ESCREVA AQUI: regra de linkagem
# $(NAME) deve depender de $(OBJ)
# A receita usa $(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ESCREVA AQUI: targets clean, fclean, re e .PHONY
# clean  → rm -f $(OBJ)
# fclean → chama clean e também remove o binário
# re     → chama fclean e depois all
