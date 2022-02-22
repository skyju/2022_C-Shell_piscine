NAME = do-op
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ./srcs/
SRC = main.c ft_atoi.c operate.c string_util.c
SRCS = ${addprefix ${DIR}, ${SRC}}

all :
	${CC} ${CFLAGS} ${SRCS} -o ${NAME}

clean :
	${RM} ${NAME}

fclean : clean

re : fclean all