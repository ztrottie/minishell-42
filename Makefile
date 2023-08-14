NAME			=	minishell

BIN_DIR			=	bin/

BUILT_DIR		=	src/built-in/
PROMPT_DIR		=	src/prompt/
ENV_DIR			=	src/env/
PARSING_DIR		=	src/parsing/
COMMANDS_DIR	=	src/commands/
HERE_DOC_DIR	=	src/here_doc/
REDIRECTION_DIR	=	src/redirection/
EXECUTION_DIR	=	src/execution/
ERROR_DIR		=	src/error/
SIGNAL_DIR		=	src/signal/
EXPORT_DIR		=	src/built-in/export/
CD_DIR			=	src/built-in/cd/
EXIT_DIR		=	src/built-in/exit/
UNSET_DIR		=	src/built-in/unset/

LIBFT_DIR		=	libft/
READLINE		=	readline/libreadline.a
HISTORY			=	readline/libhistory.a

CC				=	gcc
CFLAGS			=	-Wextra -Wall -Werror -g
LIBFT			=	$(LIBFT_DIR)libft.a

PROMPT_SRCS			=	minishell.c

ENV_SRCS			=	environment.c \
						variable.c \
						env_utils.c

PARSING_SRCS		=	parsing_init.c \
						comparison.c \
						tokens_split.c \
						tokens_list.c \
						line_utils.c \
						len_control.c \
						string_control.c \
						variable_control.c \

COMMANDS_SRCS		=	red_list.c \
						init_commands.c \
						tokens_parsing.c \
						init_contents.c

HERE_DOC_SRCS		=	here_doc.c \
						get_input.c \
						hd_len_control.c \
						hd_control.c \
						hd_variable_control.c

REDIRECTION_SRCS	=	redirection.c \
						files_list.c \
						close_all_fd.c \
						free_all.c \
						error_case.c \
						open_redirection.c \
						open_input_redirection.c \
						open_output_redirection.c

EXECUTION_SRCS		=	execution.c \
						pid_list.c \
						std_exec.c \
						exec_nofork.c \
						child_process.c \
						get_in_out.c \
						get_cmd_path.c \
						cmd_path_error.c \
						free_child.c

ERROR_SRCS			=	error.c

SIGNAL_SRCS			=	sig_handler.c

CD_SRCS				=	cd.c \
						cd_utils.c

EXPORT_SRCS			=	export_utils.c \
						export.c \
						ft_exit.c \
						print_export.c \
						create_var.c \
						export_type.c

UNSET_SRCS			=	unset.c\
						unset_utils.c

EXIT_SRCS			=	exit.c \
						ft_islonglong.c \
						ft_atoi_l.c


PROMPT_OBJS			=	$(addprefix ${BIN_DIR}, ${PROMPT_SRCS:.c=.o})
ENV_OBJS			=	$(addprefix ${BIN_DIR}, ${ENV_SRCS:.c=.o})
PARSING_OBJS		=	$(addprefix ${BIN_DIR}, ${PARSING_SRCS:.c=.o})
COMMANDS_OBJS		=	$(addprefix ${BIN_DIR}, ${COMMANDS_SRCS:.c=.o})
HERE_DOC_OBJS		=	$(addprefix ${BIN_DIR}, ${HERE_DOC_SRCS:.c=.o})
REDIRECTION_OBJS	=	$(addprefix ${BIN_DIR}, ${REDIRECTION_SRCS:.c=.o})
EXECUTION_OBJS		=	$(addprefix ${BIN_DIR}, ${EXECUTION_SRCS:.c=.o})
ERROR_OBJS			=	$(addprefix ${BIN_DIR}, ${ERROR_SRCS:.c=.o})
SIGNAL_OBJS			=	$(addprefix ${BIN_DIR}, ${SIGNAL_SRCS:.c=.o})
EXPORT_OBJS			=	$(addprefix ${BIN_DIR}, ${EXPORT_SRCS:.c=.o})
CD_OBJS				=	$(addprefix ${BIN_DIR}, ${CD_SRCS:.c=.o})
EXIT_OBJS			=	$(addprefix ${BIN_DIR}, ${EXIT_SRCS:.c=.o})
UNSET_OBJS			=	$(addprefix ${BIN_DIR}, ${UNSET_SRCS:.c=.o})

OBJS			=	$(PROMPT_OBJS) \
					$(ENV_OBJS) \
					$(COMMANDS_OBJS) \
					$(PARSING_OBJS) \
					$(REDIRECTION_OBJS) \
					$(HERE_DOC_OBJS) \
					$(EXECUTION_OBJS) \
					$(ERROR_OBJS) \
					$(SIGNAL_OBJS) \
					$(EXPORT_OBJS) \
					$(CD_OBJS) \
					$(EXIT_OBJS) \
					$(UNSET_OBJS)

${BIN_DIR}%.o: ${PROMPT_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${REDIRECTION_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${ENV_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${PARSING_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${COMMANDS_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${HERE_DOC_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${EXECUTION_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${ERROR_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${EXPORT_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${SIGNAL_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${EXIT_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${UNSET_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

${BIN_DIR}%.o: ${CD_DIR}%.c
	@${CC} ${CFLAGS} -c $< -o $@

all: $(BIN_DIR) libft built-in $(NAME)
	@echo "Minishell compiled!"

$(NAME): $(OBJS)
	@echo "Minishell compiling"
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

built-in:
	@$(MAKE) -sC $(BUILT_DIR)

clean:
	@rm -fr $(BIN_DIR)
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(BUILT_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -sC $(LIBFT_DIR) fclean
	@$(MAKE) -sC $(BUILT_DIR) fclean

re: fclean all

val: re
	valgrind --leak-check=full --show-leak-kinds=all --trace-children=yes --track-fds=yes --suppressions=supp.txt ./minishell

.PHONY:	all clean fclean re libft
