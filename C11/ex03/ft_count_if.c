#include <stdio.h>

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
}
/*
int func(char *s)
{
	return(*s == 'A') ? 1 : 0;
}

int main()
{
	char **tab = (char**)malloc(sizeof(char*) * 4);
	tab[0] = "A";
	tab[1] = "Z";
	tab[2] = "A";
	tab[3] = "NULL";
	int i = 0;
	while (i < 4)
	{
		printf("%d\n", ft_count_if(tab, 3, func));
		i++;
	}
	
}*/