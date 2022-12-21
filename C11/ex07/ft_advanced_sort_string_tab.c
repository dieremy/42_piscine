#include <stdio.h>

void	ft_swap(char **a, char **b)
{
	char *temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (!(s1[i] == s2[i]))
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *) > 0)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[j])
		{
			if (tab[j + 1] && (*cmp)(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}