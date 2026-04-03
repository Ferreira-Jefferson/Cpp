# NAME: binário gerado
NAME = textproc

# SRC: todos os arquivos fonte
SRC = main.cpp utils.cpp parser.cpp
# OBJ: objetos correspondentes
OBJ = $(SRC:.cpp=.o)

# CXX: compilador C++
CXX = c++
# INC_DIR: diretório que contém os headers
INC_DIR = inc
# CXXFLAGS: flags de compilação + flag -I para encontrar os headers em inc/
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -I$(INC_DIR)

# all: target padrão
all: $(NAME)

# Regra de linkagem
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Pattern rule com dependência nos headers
# Qualquer mudança em inc/*.hpp força recompilação dos .o afetados
%.o: %.cpp $(INC_DIR)/*.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# clean: remove objetos intermediários
clean:
	rm -f $(OBJ)

# fclean: remove objetos e binário
fclean: clean
	rm -f $(NAME)

# re: recompilação completa
re: fclean all

# .PHONY: targets que não são arquivos
.PHONY: all clean fclean re
