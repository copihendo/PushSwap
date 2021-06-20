NAME = push_swap
CC = gcc
INCLUDES =  -I ./includes/ -I ./libft/
LIBS_ADD =  -L ./libft/ -lft 
CFLAGS = -Wall -Wextra -Werror ${INCLUDES}
SRCS =  $(addprefix ./src/,\
                main.c group.c  \
				$(addprefix cmd/, push.c  reverse_rotate.c  rotate.c  swap.c  utils.c) \
				$(addprefix logic/, general.c) )
OBJS = $(SRCS:.c=.o)

all: ${NAME}
debug:      CFLAGS  += -fsanitize=address -g
debug:      fclean all 

$(NAME) :${OBJS} | tools
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBS_ADD}
tools:
	make bonus -C ./libft/
clean:
		rm -f ${OBJS}

fclean: clean
		rm -f ${NAME}
re: fclean all


