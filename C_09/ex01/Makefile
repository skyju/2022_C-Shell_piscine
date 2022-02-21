NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ./srcs/
SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS = ${addprefix ${DIR}, ${SRC}}
OBJS = ${SRCS:.c=.o}
INC = includes

.c.o :
	${CC} ${CFLAGS} -c $^ -o $@ -I ${INC}

${NAME}: ${OBJS}
	ar rc $@ ${OBJS}
	ranlib $@

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all