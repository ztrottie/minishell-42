NAME		=	minishell

BIN_DIR		=	bin/
SRCS_DIR	=	src/
LIBFT_DIR	=	libft/

CC			=	gcc
CFLAGS		=	-Wextra -Wall -Werror
LIBFT		=	$(LIBFT_DIR)libft.a

SRCS		=	minishell.c

OBJS		=	$(addprefix ${BIN_DIR}, ${SRCS:.c=.o})

${BIN_DIR}%.o: ${SRCS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) libft $(NAME)
	@echo "Minishell compiled!"

$(NAME): $(OBJS)
	@echo "minishell compiling"
	@$(CC) $(OBJS) $(LIBFT) -o $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

libft: $(LIBFT_DIR)
	@$(MAKE) -sC $(LIBFT_DIR)

$(LIBFT_DIR):
	@git clone git@github.com:ztrottie/libft.git

clean:
	@rm -fr $(BIN_DIR)
	@$(MAKE) -sC $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY:	all clean fclean re libft