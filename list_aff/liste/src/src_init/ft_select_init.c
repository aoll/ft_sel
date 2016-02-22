/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:39:54 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 18:33:05 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_select.h"

int	ft_select_ck_size_screen(t_config_liste **t_c_l)
{
	struct winsize  size;
	int				ck;

	ck = 0;
    if (ioctl(STDIN_FILENO,TIOCGWINSZ, (char*) &size) < 0)
        return (0);
	
    if ((*t_c_l)->si_y_term != (short int)size.ws_row)
	{
		(*t_c_l)->si_y_term = (short int)size.ws_row;
		ck++;
	}
	if ((*t_c_l)->si_x_term != (short int)size.ws_col)
	{
		(*t_c_l)->si_x_term = (short int)size.ws_col;
		ck++;
	}
	return (ck);
}

int	ft_select_terminal_init(struct termios *terminal)
{
    const char      *name_term;// = getenv("TERM");                                                                                   
    struct termios term;

    term = *terminal;
    if ((name_term = getenv("TERM")) == NULL)
	return (-1);
    if (tgetent(NULL, name_term) != 1)
	return (-1);
    if (tcgetattr(0, &term) == -1)
	return (-1);
    term.c_lflag &= ~(ICANON);
    term.c_lflag &= ~(ECHO);
    term.c_cc[VMIN] = 0; 
    term.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSADRAIN, &term) == -1)
	return (-1);
    ft_putstr(tgetstr("vi", NULL));
    return (0);
}

int	ft_select_struct_init(t_init **init, const int ac, const char **av)
{
    t_init *i;

    i = malloc(sizeof(t_init));
    if ((i->t_l = ft_select_liste((const int)(ac),			\
			     (const char **)(av))) == NULL)
	return (1);

    if ((i->t_c_l = ft_select_config_liste_new((const t_liste*)(i->t_l))) == NULL)
	return (1);
    if (ft_select_config_init(&i->t_c_l) < 0)
	{
	    ft_putstr("Error: terminal to small\n");//------------------------------------------------------- < 0
	    
	}
    if (!(i->t_t_c = ft_select_tree_col_new(&i->t_l, (const t_config_liste*)i->t_c_l)))
	return (1);
    ft_select_tree_tab_f(&i->t);
    if (!(ft_select_tab_key_new(&i->f)))
	return (1);
*init = i;

	return (0);
}

int	ft_select_config_with_size(t_init **init, int *ck)
{
    if (ft_select_ck_size_screen(&(*init)->t_c_l))
    {
	if (ft_select_config_init(&(*init)->t_c_l) < 0)
        {	    
	    ft_putstr("\e[1;1H\e[2J"); //clear
	    ft_putstr("Error: terminal to small\n");
	    return (-1);
	}
	(*ck)++;
	ft_select_tree_free(&(*init)->t_t_c); // return 0 si pas alloue
	if (!((*init)->t_t_c = ft_select_tree_col_new(&(*init)->t_l,	\
						      (const t_config_liste*)(*init)->t_c_l)))
	    return (-1);
    }
    return (1);
}

int	ft_select_init(t_init **init, t_kernel **ker, const int ac, const char **av)
{
    struct termios term;

    if (ft_select_terminal_init(&term) < 0)
	return (-1);
    if (ft_select_struct_init(init, (const int)(ac), (const char **)(av)) < 0)
	return (-1);
    (*ker)->ck = 1;
    (*ker)->ctrl_z = 5;
    (*ker)->loop = 0;
    (*ker)->i = 1;
    (*ker)->j = 1;
    return (0);
}
