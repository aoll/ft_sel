#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/14 17:07:06 by aollivie          #+#    #+#              #
#    Updated: 2016/02/03 12:47:52 by aollivie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_memcpy.c ft_strclr.c ft_strncmp.c ft_memdel.c ft_strcmp.c \
		ft_strncpy.c ft_atoi.c ft_memmove.c ft_strcpy.c	ft_strnequ.c \
		ft_bzero.c	ft_memset.c	ft_strdel.c	ft_strnew.c ft_isalnum.c \
		ft_putchar.c ft_strdup.c ft_strnstr.c ft_isalpha.c ft_putchar_fd.c \
		ft_strequ.c	ft_strrchr.c ft_isascii.c ft_putendl.c ft_striter.c \
		ft_strsplit.c ft_isdigit.c ft_putendl_fd.c ft_striteri.c ft_isprint.c \
		ft_putnbr.c	ft_strjoin.c ft_strstr.c ft_itoa.c ft_putnbr_fd.c \
		ft_strlcat.c ft_strsub.c ft_memalloc.c ft_putstr.c ft_strlen.c \
		ft_strtrim.c ft_memccpy.c ft_putstr_fd.c ft_strmap.c ft_tolower.c \
		ft_memchr.c	ft_strcat.c	ft_strmapi.c ft_toupper.c ft_memcmp.c \
		ft_strchr.c	ft_strncat.c ft_fc.c get_next_line.c ft_list_str_from_file.c ft_isspace.c ft_nb_c.c ft_free_list.c

OBJ = $(SRC:.c=.o)

$(NAME) :
			@gcc -Wall -Wextra -Werror -c libft.h $(SRC)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)

all : $(NAME)

clean : 
		@rm -f $(OBJ)

fclean : clean
		@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
