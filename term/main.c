#include <termios.h>
#include <unistd.h>
#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
	return;
}

int     voir_touche()
{
	char     buffer[3];
	char *res;
	//
	//checker la valide de chaque char !!!
	//
	while (1)
		{
			read(0, buffer, 3);
		
			printf("cest une touche ! ::");
			printf("%d", buffer[0] - 0);
			printf(", %d", buffer[1] - 0);
			printf(", %d\n", buffer[2] - 0);


			if (buffer[0] == 4)
				{
					printf("Ctlr+d, on quitte !\n");
					return (0);
				}
			if (buffer[2] == 66)
			{
				/**/ //REVERSE MODE
				if ((res = tgetstr("mr", NULL)) == NULL)
					return (-1);
				tputs(res, 0, putchar);
			}
			if (buffer[2] == 67)
			{
				/**/ //UNDERLINE MODE ON
				if ((res = tgetstr("us", NULL)) == NULL)
					return (-1);
				tputs(res, 0, putchar);
			}
			if (buffer[2] == 68)
			{
				/**/ // UNDERLINE OFF
				if ((res = tgetstr("ue", NULL)) == NULL)
					return (-1);
				tputs(res, 0, putchar);
			}
			if (buffer[2] == 65)
			{
				printf("%s\n", "HELLO WORLD");
				/**/ //ALL OFF
				if ((res = tgetstr("me", NULL)) == NULL)
					return (-1);
				tputs(res, 0, putchar);
			}

		}
	return (0);
}

int	main(int ac, char **av)
{
	const char	*name_term;// = getenv("TERM");
	struct termios term;
	void *f = ft_putchar;
	const char *res;

	if ((name_term = getenv("TERM")) == NULL)
	    return (-1);
	
	
	// 1 if success, 0 if there are no such entry, -1 if dqtqbqse term can't be found
	//su gnu en passant un buffer null, UNIX le buffer doit etre alloue de 2048 
	if (tgetent(NULL, name_term) != 1)
		return (-1);

	if (tcgetattr(0, &term) == -1)
		return (-1);

	//terminal mode cannonique:: un read sur lentre standart ce fera a chaque touche presse sans attendre que la touche entree soit presse :P :p
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
      	term.c_cc[VMIN] = 1; // ??
	term.c_cc[VTIME] = 0; // ??
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (-1);
	
	/**/

	voir_touche();










	
	/*
	printf("COL: %d\n", tgetnum("co"));
	printf("LIN: %d\n", tgetnum("li"));
	//tgoto & tgetstr permet de passer des parametres en char *
	//tputs l'applique
	//res = tgetstr("cl", NULL);
	//tputs(res, 0, putchar);
	res = tgetstr("rv",NULL);
	//	printf("%s\n", res); 
		tputs(res, 9, putchar);
	//printf("tpust::%d\n", tputs(tgetstr("rv", NULL), 0, putchar));

	tputs(tgoto("slt", 100, 10), 1, putchar);
	*/
return (0);
}
