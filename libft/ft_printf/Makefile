# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/12 11:41:43 by mavellan          #+#    #+#              #
#    Updated: 2025/03/12 11:41:45 by mavellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
CYAN = \033[0;96m
GREEN = \033[0;92m
BLUE = \033[0;94m
RED = \033[0;91m

NAME = libftprintf.a
CC = cc
FLAGS = -Werror -Wextra -Wall
LIBFTDIR = ../
RM = rm -f

SRC = ft_printf.c \
	ft_print_char.c \
	ft_print_hex.c \
	ft_print_int.c \
	ft_print_pointer.c \
	ft_print_string.c \
	ft_print_unsigned.c \
	ft_putunsigned.c \

OBJS = $(SRC:.c=.o)

%.o: %.c Makefile includes/ft_printf.h
	$(CC) $(FLAGS) -I. -c $< -o $@
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"

all: $(LIBFTDIR)libft.a $(NAME)

$(NAME): $(OBJS) $(LIBFTDIR)libft.a
	ar rcs $(NAME) $(OBJS) $(LIBFTDIR)libft.a

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
