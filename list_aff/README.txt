ft_select

-------
- creation liste circulaire a partir de argv
-- struct --
- char *s	: str_name
- int l   	: int_length
- int e		: int_etat (0, 1, 2, 3) // pour laffichage
- int start	: int_start (1er element de la liste) (0, 1, 2) 1 == start, 2 == end
- int y		: int_y (ligne ou se trouve lelement)
- int x		: int_col (colonne ou se trouve lelement)
-- end --

- creation struct d'affichage en fonction de term_y et term_x et la liste circulaire
-- struct --
- int y				: int_y_term
- int x				: int_x_term
- int l_max			: int_length_str_name_list
- int nb_el			: int_nombre_delement_list
- int nb_col		: int_nb_colonne
- int nb_ligne_col		: int_nb_ligne_par_colonne
- int nb_col_aff	: int_nb_col_aff
- int index_col_aff	: int_index_col_aff
-- end	--

-- stuff for --
- ioctl - permet davoir le x, et y que le terminal comporte
:: #include <termios.h> 
#include <sys/ioctl.h>

struct winsize size;

if (ioctl(STDIN_FILENO,TIOCGWINSZ, (char*) &size)<0) 
printf ("Erreur TIOCGEWINSZ\n");

printf ("votre terminal comporte %d lignes et %d colones\n", 
size.ws_row,size.ws_col);
- ioctl_end -




- cretation arbre enaire par tableau
-- struct --
- ptr_tab	: sizeof(ptr_tab) * nb_col
- cu_col	: la colonne dans laquelle ce se trouve le curseur
-- end -- 		