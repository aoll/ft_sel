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

#include "inc/ft_select.h"

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
    if (!ft_select_config_init(&i->t_c_l))
	ft_putstr("Error: terminal to small\n");
    if (!(i->t_t_c = ft_select_tree_col_new(&i->t_l, (const t_config_liste*)i->t_c_l)))
	return (1);
    ft_select_tree_tab_f(&i->t);
    if (!(ft_select_tab_key_new(&i->f)))
	return (1);

*init = i;
	return (0);
}

int	ft_select_free_liste_0(t_liste **t_l)
{
    t_liste *tmp;
    t_liste *l;

    l = *t_l;
    tmp = l;
    l = l->n;
    l->p->p->n = l;
    l->p = l->p->p;
    l->si_start = 1;
    if (l->si_etat == 1)
	l->si_etat = 3;
    else
	l->si_etat = 2;
    free(tmp->s_name);
    tmp->s_name = NULL;
    free (tmp);
    tmp = NULL; // doit etre free de linterieur !!
    *t_l = l;
    return (0);
}

int	ft_select_config_with_size(t_init **init, int *ck)
{
    if (ft_select_ck_size_screen(&(*init)->t_c_l))
    {
	if (!ft_select_config_init(&(*init)->t_c_l))
	{
	    ft_putstr("Error: terminal to small\n");
	    return (-1);
	}
	(*ck)++;
	ft_select_tree_free(&(*init)->t_t_c); // return 0 si pas alloue
	if (!((*init)->t_t_c = ft_select_tree_col_new(&(*init)->t_l,\
(const t_config_liste*)(*init)->t_c_l)))
	    return (-1);
    }
	return (0);
}

int	ft_select_print_out(int *ck, int *ctrl_z, t_init **init)
{
    char *goto_str;//, *clear_str; // doit etre free!!!!!
   
  goto_str = tgetstr("cm", NULL);    
    if ((*ck) || (*ctrl_z) > 1000000)
    {
	if ((*ctrl_z) > 1000000)
	    ft_tree_col_init_tab(&((*init)->t_t_c->ptr_tab), &(*init)->t_l, (*init)->t_c_l->i_nb_ligne_col, (*init)->t_c_l->i_nb_col);
	ft_putstr(tgoto(goto_str, 0, 0));//, stdout);
	ft_putstr("\e[1;1H\e[2J"); //clear
	ft_select_tree_print((*init)->t_t_c, (const t_config_liste*)(*init)->t_c_l, (*init)->t);
	(*ck) = 0;
	(*ctrl_z) = 0;
    }  
    return (0);
}

int	ft_select_sup(int *sup, int *ck, t_init **init)
{
	if ((*sup) == 2 || (*sup) == 3)
	{
	    if ((*sup) == 3) // pourrait se faire avec une fonction qui prend (*sup) et ladresse de liste en parametre, retourne (*sup) , mais avant si (*sup) == 3 (*sup) liste.0
	    {
		ft_select_free_liste_0(&(*init)->t_l);
	    }
	    if (((*init)->t_c_l = ft_select_config_liste_new((const t_liste*)((*init)->t_l))) == NULL)
		return (-1);
	    if (!ft_select_config_init(&(*init)->t_c_l))
	    {
		ft_putstr("Error: terminal to small\n");
		return (-1);
	    }
	    (*ck)++;
	    ft_select_tree_free(&(*init)->t_t_c); // return 0 si pas alloue
	    if (!((*init)->t_t_c = ft_select_tree_col_new(&(*init)->t_l, (const t_config_liste*)(*init)->t_c_l)))
		return (-1);
	}
	return (0);
}

int	ft_select_init_free(t_init **init)
{
    ft_select_liste_free(&(*init)->t_l); // return 0 si pas alloue
    ft_select_config_free(&(*init)->t_c_l); // return 0 si pas alloue
    ft_select_tree_free(&(*init)->t_t_c); // return 0 si pas alloue
    ft_select_tree_tab_f_free(&(*init)->t); // return 0 si pas alloue
    ft_select_tab_key_free(&(*init)->f);

    free(init); //??
    init = NULL;
	return (0);
}

int	ft_select_buff_reset(char **buff, int *loop)
{
    if ((*buff))
	free ((*buff));
    (*buff) = NULL;
    (*buff) = ft_strnew(10000);
    (*loop) = 0;
    return (0);
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
    return (0);
}

int	ft_select_read(char **buff, t_init **init, t_kernel **ker)
{
    ft_tree_col_init_tab(&((*init)->t_t_c->ptr_tab), &(*init)->t_l, (*init)->t_c_l->i_nb_ligne_col, (*init)->t_c_l->i_nb_col);
    if (((*ker)->sup = (*init)->f[ft_select_table_0((*buff))][ft_select_table_1((*buff))][ft_select_table_2((*buff))](&(*init)->t_c_l, &(*init)->t_t_c)) == 0)
	(*ker)->ck++;
    ft_select_sup(&(*ker)->sup, &(*ker)->ck, init); // en fonction du retour break et free
    ft_select_buff_reset(buff, &(*ker)->loop);
    return (0);
}


int	ft_select_kernel(const int ac, const char **av)
{
    t_kernel *ker;
    char *buff;
    t_init *init;

    ker = malloc(sizeof(t_kernel));
    if (ft_select_init(&init, &ker, ac, av) < 0 || !(buff = ft_strnew(10000)))
	return (-1);
    while (1 == 1)
    {
	if (ft_select_config_with_size(&init, &ker->ck) < 0)
	    return (-1);
	ft_select_print_out(&ker->ck, &ker->ctrl_z, &init);
	if (ker->loop > 500000)
	    if (read(0, buff, 10000) > 0)
	    {
		if (ft_select_read(&buff, &init, &ker) != 0)
		    break;
	    }
	(*ker).loop++;
	(*ker).ctrl_z++;
    }
    ft_select_init_free(&init);
    return (1);
}

void	ft_pp(int a)
{
//    static int c = 0;
    struct termios term;
    char *sp;
const char      *name_term;// = getenv("TERM");                                                                                        
  
    (void)a;
  if ((name_term = getenv("TERM")) == NULL)
      return ;
    if (tgetent(NULL, name_term) != 1)
	return ;
    if (tcgetattr(0, &term) == -1)
	return ;
  

      
 sp = ft_strnew(2);
    *sp = (char)term.c_cc[VSUSP];
    *(sp + 1) = 0;
    //if (a != 20)
    //	return ;
               
    
    term.c_lflag |= ICANON;
    term.c_lflag |=  ECHO;
     if (tcsetattr(0, 0, &term) == -1)
	 return ;
    
    
    //exit (0);
    // char    cp[2] = {term.c_cc[VSUSP], 0};
     //    signal(20, SIG_DFL); //ctrl-z
    ft_putstr("\033[?1049l"); //recharge le svg du terminal
   
    signal(SIGTSTP, SIG_DFL);
    ioctl(0, TIOCSTI, sp);
    sp = NULL;
    
    return ;
}


void ft_p(int a)
{
    const char      *name_term;// = getenv("TERM");                                                                                        
    struct termios term;
//    const char *res;

(void)a;
    ft_putstr("\033[?1049h\033[H"); //svg du terminal
    ft_putstr("\e[1;1H\e[2J"); //clear
    //signal ctrl+C
    //  signal(2, SIG_IGN);
    if ((name_term = getenv("TERM")) == NULL)
	return ;
    if (tgetent(NULL, name_term) != 1)
	return ;
    if (tcgetattr(0, &term) == -1)
	return ;
    term.c_lflag &= ~(ICANON);
    term.c_lflag &= ~(ECHO);
    term.c_cc[VMIN] = 0; 
    term.c_cc[VTIME] = 0;
    if (tcsetattr(0, TCSADRAIN, &term) == -1)
	return ;
    signal(SIGTSTP, ft_pp);
    return ;
}


int	main(int ac, char **av)
{
    //    int num_sig = 18; // fg;
    void    (*f)(int);
    // ne pas oublier diniber le ctrl-c == 2;
   // int num_sig;
    /*    
    for (num_sig = 1; num_sig < NSIG ; num_sig++)
	{
	    //      printf("%d\n", num_sig );                                                                                      
	    //if (num_sig == 2 || num_sig == 18)                                                                                   
	    
		signal(num_sig, SIG_IGN);

	    //printf("VALEUR RENVOYER: %d\n", num_sig);                                                                    
	}
    */
    
    f = (ft_p);
    ft_putstr("\033[?1049h\033[H"); //svg du terminal
    signal(18, f);
    f = (ft_pp);
    
    signal(SIGTSTP, ft_pp);
     signal(20, f); //ctrl-z
    //signal ctrl+C
    //  signal(2, SIG_IGN);

    if (!(ft_select_kernel((const int)(ac - 1), (const char **)++av)))
		return (0);
//	// printf("align %zu\n", sizeof(t_liste));
//	ft_putstr("HELLO\n");
	return (0);
}
