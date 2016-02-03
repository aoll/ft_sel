#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
void	ft_print(int i)
{
	printf("%d ", i );
	return ;
}

void	ft_ret(int i)
{
	return ;
}

void	ft_init(void (***t)(int))
{
	int i;

	i = 0;
	if (!(*t = malloc(sizeof(void *) * 101)))
		return ;
	(*t)[100] = NULL;

	while (i < 100)
	{
		if (i % 2 > 0)
			(*t)[i] = ft_print;
		else
			(*t)[i] = ft_ret;
		i++;
	}

	return ;
}
*/

int	main(void)
{
	int i;
//	void (**t)(int);
	int j;
	int w;

	
//	ft_init(&t);
	w = 0;

//while (w < 100)

	j = 0;
	while (j < 1 000 000)
	{
		i = 0;
		while (i < 100)
		{
			if (i % 2 > 0)
				printf("%i\n ", i);
			i++;
		}
		j++;
	}

	return (0);
}
