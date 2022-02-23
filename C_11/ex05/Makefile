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


===

NAME = do-op
CC = gcc
CFLAGS = -Wall -Wextra -Werror
DIR = ./srcs/
SRC = main.c ft_atoi.c operate.c string_util.c
SRCS = $(addprefix $(DIR), $(SRC))
OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
