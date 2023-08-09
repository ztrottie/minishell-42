NAME		=	pwd

BIN_DIR		=	bin/
LIBFT_DIR	=	../../../libft/

CC			=	gcc
CFLAGS		=	-Wextra -Wall -Werror
LIBFT		=	$(LIBFT_DIR)libft.a

SRCS		=	pwd.c

OBJS		=	$(addprefix ${BIN_DIR}, ${SRCS:.c=.o})

$(BIN_DIR)%.o: ./%.pwd
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) $(NAME)
	@echo "pwd compiled!"

$(NAME): $(OBJS)
	@echo "compiling pwd!"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o ../$(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

clean:
	@rm -fr $(BIN_DIR)

flcean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
