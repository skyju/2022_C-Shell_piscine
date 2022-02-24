NAME = ft_cat
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c
OBJ = ${SRC:.c=.o}

%.c : %.o
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) :
	$(CC) $(CFLAGS) $(SRC) -o $@

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)