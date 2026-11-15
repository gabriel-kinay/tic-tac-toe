# Makefile

NAME = tic-tac-toe

SRCS = tic-tac-toe.c \
	tableau.c \
	tableau.h \

all: $(NAME)

$(NAME): $(SRCS)
	gcc $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re: fclean all