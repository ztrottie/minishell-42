NAME		=	$(EXEC_DIR)pwd

BIN_DIR		=	bin/
EXEC_DIR	=	/tmp/minishell/
LIBFT_DIR	=	../../../libft/

CC			=	gcc
CFLAGS		=	-Wextra -Wall -Werror
LIBFT		=	$(LIBFT_DIR)libft.a

SRCS		=	pwd.c\
				main.c

OBJS		=	$(addprefix ${BIN_DIR}, ${SRCS:.c=.o})

$(BIN_DIR)%.o: ./%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) $(EXEC_DIR) $(NAME)
	@echo "pwd compiled!"

$(NAME): $(OBJS)
	@echo "compiling pwd!"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(EXEC_DIR):
	@mkdir -p $(EXEC_DIR)

clean:
	@rm -fr $(BIN_DIR)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
