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
/*
void	ft_p_t_c(t_config_liste *t)
{
	printf("y_term = %d,  x_term = %d, str_max = %d, i_nb_l = %d, i_nb_col = %d, i_nb_coll_aff = %d, i_index_coll_a_aff = %d\n", t->si_y_term ,  t->si_x_term ,  t->i_l_str_max ,  t->i_nb_ligne_col ,  t->i_nb_col , t->i_nb_col_aff, t->i_index_col_aff);
	return ;
}
*/

static int	ft_select_kernel(const int ac, const char **av)
{
    t_kernel *ker;
    char *buff;
    t_init *init;
 
    ker = malloc(sizeof(t_kernel));
    if (ft_select_init(&init, &ker, ac, av) < 0 || !(buff = ft_strnew(10000)))
	return (-1);
    while (1 == 1)
    {
	ft_term_print_too_small(&(*ker).i, &(*ker).j);
	ft_term_print_good_size(&init, &ker, &(*ker).i, &(*ker).j);
	if (ker->loop > 500000)
	    {
		if (read(0, buff, 10000) > 0)
		    {
			if (((*ker).key = ft_select_read(&buff, &init, &ker)) != 0) //echap ou enter
			    break;
		    }
	    }
	(*ker).loop++;
	(*ker).ctrl_z++;
    }
    ft_select_end(&init, &ker, &buff);
    //ft_select_init_free(&init);
    return (0);
}

static void	ft_restore_term(int ctrl_z)
{
        struct termios term;
	char *sp;
    const char      *name_term;// = getenv("TERM");                                                                                        
  
  if ((name_term = getenv("TERM")) == NULL)
      return ;
    if (tgetent(NULL, name_term) != 1)
	return ;
    if (tcgetattr(0, &term) == -1)
	return ;
    sp = ft_strnew(2);
    *sp = (char)term.c_cc[VSUSP];
    *(sp + 1) = 0;
    term.c_lflag |= ICANON;
    term.c_lflag |=  ECHO;
     if (tcsetattr(0, 0, &term) == -1)
	 return ;
     ft_putstr(tgetstr("ve", NULL));
    ft_putstr("\033[?1049l"); //recharge le svg du terminal
    if (ctrl_z)
	{
	    signal(SIGTSTP, SIG_DFL);
	    ioctl(0, TIOCSTI, sp);
	    sp = NULL;
	}
    return ;
}

static void	ft_ctrl_z(int a)
{
    ft_restore_term(1);
    return ;
}


static void ft_fg(int a)
{
    const char      *name_term;// = getenv("TERM");                                                                                        
    struct termios term;

    (void)a;
    ft_putstr("\033[?1049h\033[H"); //svg du terminal
    ft_putstr("\e[1;1H\e[2J"); //clear
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
    signal(SIGTSTP, ft_fg);
    ft_putstr(tgetstr("vi", NULL));
    return ;
}


int	main(int ac, char **av)
{
    void    (*f)(int);
    int num_sig;

    //ne pas oublier de boucler sur tout les signaux !!!! (il suffit de decommmenter en desous ;))        
        for (num_sig = 1; num_sig < NSIG ; num_sig++)
	{
		signal(num_sig, SIG_IGN);
		}
    f = (ft_fg);
    ft_putstr("\033[?1049h\033[H"); //svg du terminal
    signal(18, f); //fg
    f = (ft_ctrl_z);
    signal(SIGTSTP, ft_ctrl_z);
    signal(20, f); //ctrl-z
    if (!(ft_select_kernel((const int)(ac - 1), (const char **)++av)))
		return (0);
    return (0);
}
