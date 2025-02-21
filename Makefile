NAME = pipex
CC = cc
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
LIBFT_DIR = libft
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
RM = rm -f

SRCS = pipex.c \
	src/pipex_ender.c \
	src/pipex_init.c \
	src/pipex_open_files.c \
	src/pipex_runner.c \
	src/pipex_getters.c \


OBJS = ${SRCS:.c=.o}

all: $(LIBFT_DIR)libft.a $(PRINTF_DIR)libftprintf.a $(NAME)

%.o: %.c Makefile pipex.h
	$(CC) %(CFLAGS) -Ilibft -Ilibft/printf -c $< -o $@

$(NAME): $(LIBFT_DIR)libft.a $(PRINTF_DIR)libftprintf.a $(OBJS)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT_DIR)libft.a $(PRINTF_DIR)libftprintf.a -o pipex

$(LIBFT_DIR)libft.a:
	@$(MAKE)


# Clean objects
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	${RM} ${OBJS}

# Clean all files
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	${RM} ${NAME}

re: fclean all
.PHONY: all clean fclean re
