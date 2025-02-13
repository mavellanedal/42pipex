# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/11 21:17:42 by mavellan          #+#    #+#              #
#    Updated: 2025/02/11 21:26:27 by mavellan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
FLAGS = -Werror -Wextra -Wall
LIBFTDIR = ../
RM = rm -f

LIBFT_OBJ = $(addprefix $(LIBFTDIR)), \
	ft_isalpha.o \
	ft_isdigit.o \
	ft_isalnum.o \
	ft_isascii.o \
	ft_isprint.o \
	ft_strlen.o \
	ft_memset.o \
	ft_bzero.o \
	ft_memcpy.o \
	ft_memmove.o \
	ft_strlcpy.o \
	ft_strlcat.o \
	ft_toupper.o \
	ft_tolower.o \
	ft_strchr.o \
	ft_strrchr.o \
	ft_strncmp.o \
	ft_memchr.o \
	ft_memcmp.o \
	ft_strnstr.o \
	ft_atoi.o \
	ft_calloc.o \
	ft_strdup.o \
	ft_substr.o \
	ft_strjoin.o \
	ft_strtrim.o \
	ft_strndup.o \
	ft_split.o \
	ft_itoa.o \
	ft_strmapi.o \
	ft_striteri.o \
	ft_putchar_fd.o \
	ft_putstr_fd.o \
	ft_putendl_fd.o \
	ft_putnbr_fd.o \
	get_next_line.o \
	ft_lstnew_bonus.o \
	ft_lstadd_front_bonus.o \
	ft_lstsize_bonus.o \
	ft_lstlast_bonus.o \
	ft_lstadd_back_bonus.o \
	ft_lstdelone_bonus.o \
	ft_lstclear_bonus.o \
	ft_lstiter_bonus.o \
	ft_lstmap_bonus.o \
	ft_free.o \
	ft_array_count.o

SRC = ft_prinf.c \
	ft_print_char.c \
	ft_print_hex.c \
	ft_print_int.c \
	ft_print_pointer.c \
	ft_print_stinrg.c \
	ft_print_unsignec.c \
	ft_putunsigned.c \

OBJS = $(SRC:.c=.o)

%.o: %.c Makefile includes/ft_printf.h
	$(CC) $(FlAGS) -I. -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)S ${LIBFT_OBJ}
	ar rcs $(NAME) $(OBJS) ${LIBFT_OBJ}

clean:
	$(RM) $(OBJS)
fclean:
	$(RM) $(NAME)
re: fclean all

.PHONY: all clean fcelan re bonus
