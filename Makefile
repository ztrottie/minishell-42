NAME			=	minishell

BIN_DIR			=	bin/

PROMPT_DIR		=	src/prompt/
BUILT_DIR		=	src/built-in/
ERROR_DIR		=	src/error/
ENV_DIR			=	src/env/
PARSING_DIR		=	src/parsing/

LIBFT_DIR		=	libft/
READLINE		=	readline/libreadline.a
HISTORY			=	readline/libhistory.a

CC				=	gcc
CFLAGS			=	-Wextra -Wall -Werror -g
LIBFT			=	$(LIBFT_DIR)libft.a

PROMPT_SRCS		=	minishell.c

ERROR_SRCS		=	ft_exit.c

ENV_SRCS		=	environment.c \
					variable.c \
					env_utils.c

BUILT_SRCS		=	echo.c\
					pwd.c\
					env.c

PARSING_SRCS	=	parsing_init.c \
					comparison.c \
					tokens_split.c \
					tokens_list.c \
					line_utils.c \
					len_control.c \
					string_control.c \
					tokens_parsing.c \
					variable_control.c

PROMPT_OBJS		=	$(addprefix ${BIN_DIR}, ${PROMPT_SRCS:.c=.o})
ENV_OBJS		=	$(addprefix ${BIN_DIR}, ${ENV_SRCS:.c=.o})
BUILT_OBJS		=	$(addprefix ${BIN_DIR}, ${BUILT_SRCS:.c=.o})
ERROR_OBJS		=	$(addprefix ${BIN_DIR}, ${ERROR_SRCS:.c=.o})
PARSING_OBJS	=	$(addprefix ${BIN_DIR}, ${PARSING_SRCS:.c=.o})

${BIN_DIR}%.o: ${PROMPT_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${ENV_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${BUILT_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${ERROR_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${PARSING_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) libft $(NAME)
	@echo "Minishell compiled!"

$(NAME): $(PROMPT_OBJS) $(ENV_OBJS) $(ERROR_OBJS) $(PARSING_OBJS) $(BUILT_OBJS)
	@echo "minishell compiling"
	@$(CC) $(CFLAGS) $(PROMPT_OBJS) $(ENV_OBJS) $(ERROR_OBJS) $(BUILT_OBJS) $(PARSING_OBJS) -l readline -l ncurses $(READLINE) $(HISTORY) $(LIBFT) -o $(NAME)

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

val: all
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=supp.txt ./minishell

.PHONY:	all clean fclean re libft