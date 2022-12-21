#include <stdlib.h>
#include <stdio.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new;
	int	i;

	if (!(new = (int*)malloc(sizeof(int) * length)))
		return (0);
	i = 0;
	while (i < length)
	{
		new[i] = f(tab[i]);
		i++;
	}
	return (new);
}
/*
int func(int v)
{
	return(v * 30);
}

int main()
{
	int i = 0;

	int tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int* res = ft_map(tab, 10, &func);
	while (i < 10)
	{
		printf("%d\n", res[i]);
		i++;
	}
}*/