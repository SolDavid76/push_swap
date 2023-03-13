SRCS_DIR	= srcs/

SRC			= ft_split.c lst.c lst2.c main.c parsing.c utils.c move.c sorting.c pre_sorting.c

SRCS		= $(addprefix $(SRCS_DIR), $(SRC))

OBJS_DIR	= objs/

OBJ			= ${SRC:.c=.o}

OBJS		= $(addprefix $(OBJS_DIR), $(OBJ))

NAME		= push_swap

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

INCS		= -I ./includes/

all:		${OBJS_DIR} ${NAME}

${OBJS_DIR}:
			mkdir ${OBJS_DIR}

${OBJS_DIR}%.o: ${SRCS_DIR}%.c
			${CC} ${CFLAGS} -c $< -o $@ ${INCS}

${NAME}:	${OBJS}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
			rm -rf ${OBJS_DIR}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
