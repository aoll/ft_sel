#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_p(int s)
{
	printf("VAL: %d, %s\n",s, "SALUT");
	if (s == 2)
		exit(1);
	//	else if (s != 18)
	//	signal(s, SIG_DFL);
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
	
	f = (ft_p);
	printf("%d\n", NSIG);
	

		for (num_sig = 1; num_sig < NSIG ; num_sig++)
		{
			//	printf("%d\n", num_sig );
			if (num_sig == 2 || num_sig == 18)
				signal(num_sig, f);
				//printf("VALEUR RENVOYER: %d\n", num_sig);
		}

			while (1 ==1)
		{
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
