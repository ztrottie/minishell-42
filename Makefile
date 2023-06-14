NAME			=	minishell

BIN_DIR			=	bin/
PROMPT_DIR		=	src/prompt/
CMDS_DIR		=	src/cmds/
LIBFT_DIR		=	libft/

CC				=	gcc
CFLAGS			=	-Wextra -Wall -Werror
LIBFT			=	$(LIBFT_DIR)libft.a

PROMPT_SRCS		=	minishell.c

CMDS_SRCS		=	commands_init.c

PROMPT_OBJS		=	$(addprefix ${BIN_DIR}, ${PROMPT_SRCS:.c=.o})
CMDS_OBJS		=	$(addprefix ${BIN_DIR}, ${CMDS_SRCS:.c=.o})

${BIN_DIR}%.o: ${PROMPT_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${CMDS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) libft $(NAME)
	@echo "Minishell compiled!"

$(NAME): $(PROMPT_OBJS) $(CMDS_OBJS)
	@echo "minishell compiling"
	@$(CC) -lreadline $(PROMPT_OBJS) $(CMDS_OBJS) $(LIBFT) -o $(NAME)

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

libft:
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
        echo "libft directory does not exist, cloning..."; \
        git clone -q git@github.com:ztrottie/libft.git $(LIBFT_DIR); \
    else \
        echo "libft directory already exists, pulling latest version..."; \
        cd $(LIBFT_DIR) && git pull; \
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