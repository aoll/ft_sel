#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include "inc/ft_select_liste.h"
#include "inc/ft_select_config_liste.h"
#include "inc/ft_select_tree_col.h"
#include "inc/ft_select_tab_key.h"
#include <sys/ioctl.h>
#include <term.h>
#include <termios.h>
#include <signal.h>


void	ft_test(int a)
{
    static char *s;

    if (a == 1)
	s = ft_strdup("hello");
    else if (a == 2)
	return;
}


void	ft_p(int s)
{
    //	printf("VAL: %d, %s\n",s, "SALUT");
	if (s == 2)
	    ft_test(2);
	//else if (s != 18)
	//  signal(s, SIG_DFL);
//printf("%s\n", "ZZZZZ");
	return;
}

void	ft_pt(void)
{
	printf("%s\n", "okkkokok");
	return;
}

int	main(void)
{
	int num_sig;
	int		val_sig;
	void	(*f)(int);
	char *buf;
	
	f = (ft_p);
	printf("%d\n", NSIG);
	

		for (num_sig = 1; num_sig < NSIG ; num_sig++)
		{
			//	printf("%d\n", num_sig );
			if (num_sig == 2 || num_sig == 18)
				signal(num_sig, SIG_IGN);
				//printf("VALEUR RENVOYER: %d\n", num_sig);
		}
		ft_test(1);
		while (1 ==1)
		{
		    read(0, buf, 3);
		    printf("%d, %d, %d\n", buf[0], buf[1], buf[2]);
		    buf = ft_strnew(0);
		}
		
	
	/*
	for (;;)
		{
		}
	*/
	/*
	for (;;)
		{
			signal(9, SIG_IGN);
			signal(19, SIG_IGN);
			signal(32, SIG_IGN);
			signal(33, SIG_IGN);
		}
	*/
		return (0);
}
