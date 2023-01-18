NAME = push_swap
CFLAGS = -Werror -Wextra -Wall
CC = cc

SRCS = moves.c \
	utils.c \
	utils2.c \
	sort_algos.c \
	main_helpers.c \
	moves2.c\
	libft/ft_atoi.c \
	libft/ft_isdigit.c \
	libft/ft_lstadd_back.c \
	libft/ft_lstadd_front.c \
	libft/ft_lstiter.c \
	libft/ft_lstnew.c \
	libft/ft_lstsize.c \
	libft/ft_lstlast.c \
	libft/ft_putchar_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strlen.c \
	libft/ft_strncmp.c \
	libft/ft_substr.c \
	libft/ft_calloc.c \
	libft/ft_bzero.c \

MAIN = main.c
SRCS_B = bonus/gnl/get_next_line.c \
		bonus/gnl/get_next_line_utils.c \
		bonus/checker.c

CHECKER = checker

MAIN_OBJ = ${MAIN:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}

san = -fsanitize=address -g3

all: ${NAME}

${NAME}: ${OBJS} ${MAIN_OBJ}
		${CC} ${CFLAGS} ${OBJS} ${MAIN_OBJ} -o ${NAME}

${CHECKER}: ${OBJS_B} ${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${OBJS_B} -o ${CHECKER}

bonus : ${CHECKER} 
clean:
	rm -rf ${OBJS} ${OBJS_B} ${MAIN_OBJ}

fclean: clean
	rm -rf ${NAME} ${CHECKER}

re: fclean all

.PHONY: all clean fclean re bonus