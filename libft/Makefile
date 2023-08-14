NAME		=	libft.a

BINDIR		=	bin/
INCDIR		=	includes/

COMP_DIR		=	src/comparison/
CONV_DIR		=	src/conversion/
GET_DIR			=	src/get_next_line/
LIST_DIR		=	src/list/
MEM_DIR			=	src/memory/
PRINT_DIR		=	src/printf/
PRIND_DIR		=	src/printf_fd/
STR_DIR			=	src/string/
WRITE_DIR		=	src/write_fd/



COMP_SRCS	=	ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isint.c \
				ft_strishexa.c \
				ft_isspace.c


CONV_SRCS	=	ft_atoi.c \
				ft_itoa.c \
				ft_tolower.c \
				ft_toupper.c \
				ft_liatoi.c

GET_SRCS	=	get_next_line_utils.c \
				get_next_line.c

LIST_SRCS	=	ft_lstadd_back.c \
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstlast.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_lstsize.c

MEM_SRCS	=	ft_bzero.c \
				ft_calloc.c \
				ft_free.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memmove.c \
				ft_memset.c \
				ft_memcpy.c

PRINT_SRCS	=	ft_hexa_len.c \
				ft_pointer.c \
				ft_printf.c \
				ft_putnbr_base_ul.c \
				ft_putnbr_base.c \
				ft_putnbr_len.c \
				ft_putnbr_printf.c \
				ft_putnbr_u.c \
				ft_putstr_printf.c

PRIND_SRCS	=	ft_hexa_len_fd.c \
				ft_pointer_fd.c \
				ft_printf_fd.c \
				ft_putnbr_base_ul_fd.c \
				ft_putnbr_base_fd.c \
				ft_putnbr_len_fd.c \
				ft_putnbr_printf_fd.c \
				ft_putnbr_u_fd.c \
				ft_putstr_printf_fd.c

STR_SRCS	=	ft_split.c \
				ft_strchr.c \
				ft_strdup.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_strlen.c \
				ft_strmapi.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strtrim.c \
				ft_substr.c \
				ft_word_count.c \
				ft_strcmp.c \
				ft_strsearch.c

WRITE_SRCS	=	ft_putchar_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c

COMP_OBJS		=	$(addprefix ${BINDIR}, ${COMP_SRCS:.c=.o})
CONV_OBJS		=	$(addprefix ${BINDIR}, ${CONV_SRCS:.c=.o})
GET_OBJS		=	$(addprefix ${BINDIR}, ${GET_SRCS:.c=.o})
LIST_OBJS		=	$(addprefix ${BINDIR}, ${LIST_SRCS:.c=.o})
MEM_OBJS		=	$(addprefix ${BINDIR}, ${MEM_SRCS:.c=.o})
PRINT_OBJS		=	$(addprefix ${BINDIR}, ${PRINT_SRCS:.c=.o})
PRIND_OBJS		=	$(addprefix ${BINDIR}, ${PRIND_SRCS:.c=.o})
STR_OBJS		=	$(addprefix ${BINDIR}, ${STR_SRCS:.c=.o})
WRITE_OBJS		=	$(addprefix ${BINDIR}, ${WRITE_SRCS:.c=.o})

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all: $(BINDIR) $(NAME)
	@echo "libft compiled"

$(BINDIR):
	@mkdir -p bin

${BINDIR}%.o: ${COMP_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${CONV_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${GET_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${LIST_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${MEM_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${PRINT_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${PRIND_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${STR_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

${BINDIR}%.o: ${WRITE_DIR}%.c
	@${CC} ${CFLAGS} -I${INCDIR} -I. -c $< -o $@

$(NAME): $(COMP_OBJS) $(CONV_OBJS) $(GET_OBJS) $(LIST_OBJS) $(MEM_OBJS) $(PRINT_OBJS) $(STR_OBJS) $(WRITE_OBJS) $(PRIND_OBJS)
	@echo "compiling libft!"
	@ar -rcs  $(NAME) $(COMP_OBJS) $(CONV_OBJS) $(GET_OBJS) $(LIST_OBJS) $(MEM_OBJS) $(PRINT_OBJS) $(STR_OBJS) $(WRITE_OBJS) $(PRIND_OBJS)

clean:  
	@rm -fr $(BINDIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all fclean clean re