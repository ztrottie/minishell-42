NAME		=	echo

BIN_DIR		=	bin/
LIBFT_DIR	=	../../../libft/

CC			=	gcc
CFLAGS		=	-Wextra -Wall -Werror
LIBFT		=	$(LIBFT_DIR)libft.a

SRCS		=	echo.c \
				main.c

OBJS		=	$(addprefix ${BIN_DIR}, ${SRCS:.c=.o})

$(BIN_DIR)%.o: ./%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) $(NAME)
	@echo "echo compiled!"

$(NAME): $(OBJS)
	@echo "compiling echo!"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o ../bin/$(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@rm -fr $(BIN_DIR)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
