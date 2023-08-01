NAME			=	minishell

BIN_DIR			=	bin/

PROMPT_DIR		=	src/prompt/
BUILT_DIR		=	src/built-in/
ERROR_DIR		=	src/error/
ENV_DIR			=	src/env/
PARSING_DIR		=	src/parsing/
COMMANDS_DIR	=	src/commands/
HERE_DOC_DIR	=	src/here_doc/
EXECUTION_DIR	=	src/execution/

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
					variable_control.c \

COMMANDS_SRCS	=	pid_list.c \
					red_list.c \
					init_commands.c \
					tokens_parsing.c \
					init_contents.c

HERE_DOC_SRCS	=	here_doc.c \
					get_input.c \
					hd_len_control.c \
					hd_control.c \
					hd_variable_control.c

EXECUTION_SRCS	=	redirection.c \
					files_list.c \
					close_all_fd.c \
					free_all.c \
					error_case.c \
					open_redirection.c

PROMPT_OBJS		=	$(addprefix ${BIN_DIR}, ${PROMPT_SRCS:.c=.o})
ENV_OBJS		=	$(addprefix ${BIN_DIR}, ${ENV_SRCS:.c=.o})
BUILT_OBJS		=	$(addprefix ${BIN_DIR}, ${BUILT_SRCS:.c=.o})
ERROR_OBJS		=	$(addprefix ${BIN_DIR}, ${ERROR_SRCS:.c=.o})
PARSING_OBJS	=	$(addprefix ${BIN_DIR}, ${PARSING_SRCS:.c=.o})
COMMANDS_OBJS	=	$(addprefix ${BIN_DIR}, ${COMMANDS_SRCS:.c=.o})
HERE_DOC_OBJS	=	$(addprefix ${BIN_DIR}, ${HERE_DOC_SRCS:.c=.o})
EXECUTION_OBJS	=	$(addprefix ${BIN_DIR}, ${EXECUTION_SRCS:.c=.o})

OBJS			=	$(PROMPT_OBJS) $(ENV_OBJS) $(ERROR_OBJS) $(COMMANDS_OBJS) $(PARSING_OBJS) $(EXECUTION_OBJS) $(HERE_DOC_OBJS)

${BIN_DIR}%.o: ${PROMPT_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${EXECUTION_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${ENV_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${BUILT_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${ERROR_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${PARSING_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${COMMANDS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${HERE_DOC_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) libft $(NAME)
	@echo "Minishell compiled!"

$(NAME): $(OBJS)
	@echo "minishell compiling"
	@$(CC) $(CFLAGS) $(OBJS) -l readline -l ncurses $(READLINE) $(HISTORY) $(LIBFT) -o $(NAME)

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

val: re
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=supp.txt ./minishell

.PHONY:	all clean fclean re libft
