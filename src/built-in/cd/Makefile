NAME		=	$(EXEC_DIR)cd

BIN_DIR		=	bin/
LIBFT_DIR	=	../../../libft/
EXEC_DIR	=	/tmp/minishell/

CC			=	gcc
CFLAGS		=	-Wextra -Wall -Werror
LIBFT		=	$(LIBFT_DIR)libft.a

SRCS		=	cd.c \
				main.c

OBJS		=	$(addprefix ${BIN_DIR}, ${SRCS:.c=.o})

$(BIN_DIR)%.o: ./%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) $(EXEC_DIR) $(NAME)
	@echo "cd compiled!"

$(NAME): $(OBJS)
	@echo "compiling cd!"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(EXEC_DIR):
	@mkdir -p $(EXEC_DIR)

clean:
	@rm -fr $(BIN_DIR)

flcean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
