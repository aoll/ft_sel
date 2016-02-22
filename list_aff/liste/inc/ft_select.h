#ifndef FT_SELECT_H
#define FT_SELECT_H


#include "ft_select_liste.h"
#include "ft_select_config_liste.h"
#include "ft_select_tree_col.h"
#include "ft_select_tab_key.h"
//#include "ft_select_init.h"
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

typedef struct s_kernel	t_kernel;
struct	s_kernel
{
    int ck;
    int loop;
    int sup;
    int ctrl_z;
    int key;
    short int j;
    short int i;
};

void	ft_restore_term(int ctrl_z);

int     ft_select_ck_size_screen(t_config_liste **t_c_l);
int     ft_select_terminal_init(struct termios *terminal);
int     ft_select_struct_init(t_init **init, const int ac, const char **av);
int     ft_select_config_with_size(t_init **init, int *ck);
int     ft_select_init(t_init **init, t_kernel **ker, const int ac, const char **av);

int     ft_select_free_liste_0(t_liste **t_l);
int     ft_select_init_free(t_init **init);
int     ft_select_end(t_init **init, t_kernel **ker, char **buff);
int     ft_select_sup(int *sup, int *ck, t_init **init);
int     ft_select_out(t_liste *t_l);

int     ft_select_print_out(int *ck, int *ctrl_z, t_init **init);
int     ft_term_print_too_small(short int *i, short int *j);
int     ft_term_print_good_size(t_init **init, t_kernel **ker, short int *i, short int *j);

int     ft_ck_size(void);
int     ft_select_read(char **buff, t_init **init, t_kernel **ker);
int     ft_select_buff_reset(char **buff, int *loop);

//void	ft_pp(int a);


#endif
