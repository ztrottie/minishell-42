NAME		=	minishell

BIN_DIR		=	bin/
PROMPT_DIR	=	src/prompt/
PARSING_DIR	=	src/parsing/
LIBFT_DIR	=	libft/

CC			=	gcc
CFLAGS		=	-Wextra -Wall -Werror
LIBFT		=	$(LIBFT_DIR)libft.a

PROMPT_SRCS	=	minishell.c

PARSING_SRCS	=	parsing.c

PROMPT_OBJS		=	$(addprefix ${BIN_DIR}, ${PROMPT_SRCS:.c=.o})
PARSING_OBJS	=	$(addprefix ${BIN_DIR}, ${PARSING_SRCS:.c=.o})

${BIN_DIR}%.o: ${PROMPT_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${PARSING_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) libft $(NAME)
	@echo "Minishell compiled!"

$(NAME): $(PROMPT_OBJS) $(PARSING_OBJS)
	@echo "minishell compiling"
	@$(CC) -lreadline $(PROMPT_OBJS) $(PARSING_OBJS) $(LIBFT) -o $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		echo "libft directory does not exist, cloning..."; \
		git clone -q git@github.com:ztrottie/libft.git $(LIBFT_DIR); \
	fi
	@$(MAKE) -sC $(LIBFT_DIR)

clean:
	@rm -fr $(BIN_DIR)
	@$(MAKE) -sC $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean

re: fclean all

.PHONY:	all clean fclean re libft