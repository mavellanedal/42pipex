# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 11:42:25 by mavellan          #+#    #+#              #
#    Updated: 2025/03/12 11:42:27 by mavellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
CYAN = \033[0;96m
GREEN = \033[0;92m
BLUE = \033[0;94m
RED = \033[0;91m

NAME = pipex
CC = cc
FLAGS = -Werror -Wall -Wextra -g
LIBFTDIR = libft/
PRINTFDIR = libft/ft_printf/
RM = rm -f

SRCS = pipex.c \
	src/pipex_ender.c \
	src/pipex_init.c \
	src/pipex_open_files.c \
	src/pipex_runner.c \
	src/pipex_getters.c \

OBJS = $(SRCS:.c=.o)

all: $(LIBFTDIR)libft.a $(PRINTFDIR)libftprintf.a $(NAME)

%.o: %.c Makefile pipex.h
	$(CC) $(FLAGS) -Ilibft -Ilibft/ft_printf -c $< -o $@
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

$(NAME): $(LIBFTDIR)libft.a $(PRINTFDIR)libftprintf.a $(OBJS)
	@echo "$(GREEN)Compiling pipex!$(DEF_COLOR)"
	$(CC) $(FLAGS) $(OBJS) $(LIBFTDIR)libft.a $(PRINTFDIR)libftprintf.a -o $(NAME)
	@echo "$(GREEN)Pipex compiled!$(DEF_COLOR)"

$(LIBFTDIR)libft.a:
	@echo "$(CYAN)Building libft.a!$(DEF_COLOR)"
	@$(MAKE) -C $(LIBFTDIR)

$(PRINTFDIR)libftprintf.a: $(LIBFTDIR)libft.a
	@echo "$(CYAN)Building libftprintf.a!$(DEF_COLOR)"
	@$(MAKE) -C $(PRINTFDIR)

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	@$(MAKE) clean -C $(PRINTFDIR)
	@$(RM) $(OBJS)
	@echo "$(RED)Cleaned object files$(DEF_COLOR)"

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	@$(MAKE) fclean -C $(PRINTFDIR)
	@$(RM) $(NAME)
	@echo "$(RED)Cleaned all binaries$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re libft ft_printf
