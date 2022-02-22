TARGET = rush-02

SRCS = ${wildcard ./srcs/*.c}

OBJ = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o $@
# .c.o에서 .c가 의존성이니까, $<는 c파일을 의미함
# -o $@ 부분은 현재 의존파일위치가 ./srcs이므로 타겟위치도 ./src안으로 지정해주기 위함

${TARGET}: ${OBJ}
	${CC} -o $@ $^

all: ${TARGET} clean

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${TARGET}

re: fclean all

.PHONY: all clean fclean re
