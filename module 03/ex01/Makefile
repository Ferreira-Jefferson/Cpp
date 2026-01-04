NAME=scavTrap

CC		= c++
CFLAGS	= -Wall -Werror -Wextra -std=c++98 -g

OBJS_FOLDER = ./obj/
SRC			=  main.cpp ClapTrap.cpp ScavTrap.cpp
OBJS		= $(addprefix $(OBJS_FOLDER), $(SRC:.cpp=.o))

all: $(OBJS_FOLDER) $(NAME)

$(OBJS_FOLDER):
	@mkdir -p $(OBJS_FOLDER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS_FOLDER)%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_FOLDER)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re