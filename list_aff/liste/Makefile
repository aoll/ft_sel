#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aollivie <aollivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/02 08:22:38 by aollivie          #+#    #+#              #
#    Updated: 2016/02/04 17:36:40 by aollivie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = list.exe
FLAG= -Wextra -Wall -Wpadded -Wstrict-prototypes -Wwrite-strings -Wconversion
IDIR = ../../libft/libft.a
LIB=-lncurses
SRC =  main_list.c src_liste/ft_select_liste.c src_liste/ft_select_liste_free.c\
		src_config_liste/ft_select_config_liste.c\
		src_config_liste/ft_select_config_init.c\
		src_config_liste/ft_select_config_free.c\
		src_tree_col/ft_select_tree_col.c\
		src_tree_col/ft_select_tree_print.c\
		src_tree_col/ft_select_tree_tab_f.c\
		src_tree_col/ft_select_tree_tab_f_free.c\
		src_tree_col/ft_select_tree_free.c\
		src_tab_key/ft_select_tab_key.c\
		src_tab_key/ft_select_tab_func_ctrl.c\
		src_tab_key/ft_select_tab_func_mouv.c\
		src_tab_key/ft_select_table.c
		
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make -C ../.././libft/
	@gcc $(OBJ) $(IDIR) $(LIB) -o $(NAME)
%.o: %.c
	@gcc -c $(FLAG) $< -o $@

clean:
	@rm -f $(OBJ)
	@make  clean -C ../.././libft

fclean: clean
	@rm -f $(NAME)
	@make  fclean -C ../.././libft

re: fclean all

.PHONY : all clean fclean re
