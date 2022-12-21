#include <stdio.h>

int	ft_any(char **tab, int(*f)(char*))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
/*
int func(char *s)
{
	return (*s == 'A') ? 1 : 0;
}

int main()
{
	char **tab = (char**)malloc(sizeof(char*) * 3);
	int i = 0;
	tab[0] = "t";
	tab[1] = "R";
	tab[2] = "A";
	while (i < 3)
	{
		printf("%d\n", ft_any(&tab[i], func));
		i++;
	}
}*/