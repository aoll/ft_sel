#ifndef FT_SELECT_H
#define FT_SELECT_H


#include "ft_select_liste.h"
#include "ft_select_config_liste.h"
#include "ft_select_tree_col.h"
#include "ft_select_tab_key.h"
#include <sys/ioctl.h>
#include <term.h>
#include <termios.h>
#include <signal.h>


typedef struct s_init	t_init;
struct	s_init
{
    t_liste		*t_l;
    t_config_liste	*t_c_l;
    t_tree_col		*t_t_c;
    void		(**t)(const char *, int _pa);
    int			(****f)(t_config_liste **t_c_l, t_tree_col **t_t_c);
};

#endif
