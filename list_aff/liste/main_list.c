/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aollivie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:39:54 by aollivie          #+#    #+#             */
/*   Updated: 2016/02/04 18:33:05 by aollivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/ft_select_liste.h"
#include "inc/ft_select_config_liste.h"
#include "inc/ft_select_tree_col.h"
#include "inc/ft_select_tab_key.h"
#include <sys/ioctl.h>
#include <term.h>
#include <termios.h>
#include <signal.h>

void	ft_p_t_c(t_config_liste *t)
{
	printf("y_term = %d,  x_term = %d, str_max = %d, i_nb_l = %d, i_nb_col = %d, i_nb_coll_aff = %d, i_index_coll_a_aff = %d\n", t->si_y_term ,  t->si_x_term ,  t->i_l_str_max ,  t->i_nb_ligne_col ,  t->i_nb_col , t->i_nb_col_aff, t->i_index_col_aff);
	return ;
}

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

int	ft_select_kernel(const int ac, const char **av)
{
	t_liste			*l;
	t_config_liste	*t_c_l;
	t_tree_col	*t_t_c;
	void	(**t)(const char *, int _pa);
	int	(****f)(t_config_liste **t_c_l, t_tree_col **t_t_c);//(int z, int y, int x);
	int ck;
	char *buff;
	//	t_key *key;
	int size_screen;
	/*
	if (!(key = malloc(sizeof(t_key))))
	    return (0);
	*/
	    if ((l = ft_select_liste((const int)(ac),			\
						(const char **)(av))) == NULL)
		return (0);

	if ((t_c_l = ft_select_config_liste_new((const t_liste*)(l))) == NULL)
	    return (0);

	if (!ft_select_config_init(&t_c_l))
		ft_putstr("Error: terminal to small\n");
//	ft_p_t_c(t_c_l); // print verif

	if (!(t_t_c = ft_select_tree_col_new(&l, (const t_config_liste*)t_c_l)))
		return (0);
	ft_select_tree_tab_f(&t);


	if (!(ft_select_tab_key_new(&f)))
		return (0);
/*
	f[1][1][1]();
	ft_select_tree_print((const t_liste**)t_t_c->ptr_tab, (const t_config_liste*)t_c_l, t);
*/ //a virer!!
	/*	
	ft_putstr("\e[1;1H\e[2J");
	ft_select_tree_print(t_t_c, (const t_config_liste*)t_c_l, t);
	//ft_select_tree_free(&t_t_c); // return 0 si pas alloue
	ft_tree_col_init_tab(&(t_t_c->ptr_tab), &l, t_c_l->i_nb_ligne_col, t_c_l->i_nb_col);
	ft_putstr("\e[1;1H\e[2J");
	ft_select_tree_print(t_t_c, (const t_config_liste*)t_c_l, t);
	return (0);
	*/

	ck = 1;
	buff = ft_strnew(3);
	//	while (1 == 1)
	while (1 == 1)
	    {
		if (ft_select_ck_size_screen(&t_c_l))
		    {
			//	ft_putstr("SIZE\n");// debug
			// t_c_l a FREE
			if (!ft_select_config_init(&t_c_l))
			    {
				ft_putstr("Error: terminal to small\n");
				return (0);
			    }
			ck++;
			ft_select_tree_free(&t_t_c); // return 0 si pas alloue
			if (!(t_t_c = ft_select_tree_col_new(&l, (const t_config_liste*)t_c_l)))
			    return (0);
		    }
	 
		if (ck)
		    {
			ft_putstr("\e[1;1H\e[2J");
			ft_select_tree_print(t_t_c, (const t_config_liste*)t_c_l, t);
			ck = 0;
		    }
		if (read(0, buff, 3) > 0)
		    {/*
			// A CHANGER PAS DE NORMAL DE FREE ET DE DEVOIR REENITIALISER LA LE TABLEAU DE LISTE
			if (!(t_t_c = ft_select_tree_col_new(&l, (const t_config_liste*)t_c_l)))
			    return (0); // PAS NORMAL !!! PBS DANS LA FOCNTION DE PRINT AVEC LES ADRESSES AU LIEU DE SEULEMENT\
			//PARCOURIR LA LISTE ET LAFICHER BOUGE LADRESSE DE LA LISTE !!!!!
			*/
			//
			//
			ft_tree_col_init_tab(&(t_t_c->ptr_tab), &l, t_c_l->i_nb_ligne_col, t_c_l->i_nb_col);
			if (f[ft_select_table_0(buff)][ft_select_table_1(buff)][ft_select_table_2(buff)](&t_c_l, &t_t_c) == 0)
			    ck++;
			buff = ft_strnew(3);
		    }
	    }
	ft_select_liste_free(&l); // return 0 si pas alloue
	ft_select_config_free(&t_c_l); // return 0 si pas alloue
	ft_select_tree_free(&t_t_c); // return 0 si pas alloue
	ft_select_tree_tab_f_free(&t); // return 0 si pas alloue

	return (1);
}

	//printf("z == %d, y == %d, x == %d\n", k->z, k->y, k->x);
		    /*
			ft_putchar('|');
			ft_putnbr(ft_select_table_0(&k, buff));
			ft_putchar(':');
			ft_putnbr(ft_select_table_1(&k, buff));
			ft_putchar(':');
			ft_putnbr(ft_select_table_2(&k, buff));
			ft_putchar('|');	
		    */
		    //f[2][1][3]();


//++av , ac - 1//

int	main(int ac, char **av)
{
    const char      *name_term;// = getenv("TERM");                                                                                        
    struct termios term;
    //  void *f = ft_putchar;
    const char *res;

    //signal ctrl+C
    //  signal(2, SIG_IGN);

    if ((name_term = getenv("TERM")) == NULL)
	return (-1);
    // 1 if success, 0 if there are no such entry, -1 if dqtqbqse term can't be found                                                      
    //su gnu en passant un buffer null, UNIX le buffer doit etre alloue de 2048                                                            
    if (tgetent(NULL, name_term) != 1)
	return (-1);
    if (tcgetattr(0, &term) == -1)
	return (-1);
    //terminal mode cannonique:: un read sur lentre standart                                                                               
    //ce fera a chaque touche presse sans attendre que la touche entree soit press                                                         
    term.c_lflag &= ~(ICANON);
    term.c_lflag &= ~(ECHO);
    term.c_cc[VMIN] = 0; // ??                                                                                                             
    term.c_cc[VTIME] = 0; // ??                                                                                                            
    if (tcsetattr(0, TCSADRAIN, &term) == -1)
	return (-1);



	if (!(ft_select_kernel((const int)(ac - 1), (const char **)++av)))
		return (0);
//	printf("align %zu\n", sizeof(t_liste));
//	ft_putstr("HELLO\n");
	return (0);
}
