NAME = parser
SRC = main.cpp parser.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
# INC_DIR aponta para o diretório que contém os headers
INC_DIR = inc
# -I$(INC_DIR) diz ao compilador onde procurar os arquivos #include "..."
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# $(INC_DIR)/*.hpp como pré-requisito garante recompilação quando headers mudam
%.o: %.cpp $(INC_DIR)/*.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
