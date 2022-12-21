#include <stdio.h>

//mine
int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			flag = 1;
		else if (f(tab[i], tab[i + 1]) <= 0)
			flag = 1;
		else
		{
			//flag = 0;
			return 0;
		}
		i++;
	}

	return 1;
	/*if (flag == 0)
	{
		i = 0;
		while (i < length - 1)
		{
			
			else
			{
				flag = 0;
				return 0;
			}
			i++;
		}
	}
	if (flag == 1)
		return (1);
	return (0);*/
}

int	ft_sort(int *tab, int length, int(*f)(int, int))
{
	int i = 0;
	int sorted = 1;

	while (i < length - 1 && sorted)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			sorted = 0;
		i++;
	}
	if (sorted != 1)
	{
		sorted = 1;
		i = 0;
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}

int func(int a, int b)
{
	return (a - b);
}

int main()
{
	int tab1[] = {7, 6, 6, 6, 5, 5, 3, 2, 2, 1, 1, 0, 0};
	int tab2[] = {9, 22, 34, 0, 4, 2, 3, 8};
	int tab3[] = {0, 0, 1, 1, 2, 2, 3, 5, 5, 6, 6, 6, 7};
	printf("mine = %d\n", ft_is_sort(tab1, 10, &func));
	printf("%d\n", ft_sort(tab1, 10, &func));
	printf("mine = %d\n", ft_is_sort(tab2, 4, &func));
	printf("%d\n", ft_sort(tab2, 4, &func));
	printf("mine = %d\n", ft_is_sort(tab3, 13, &func));
	printf("%d\n", ft_sort(tab3, 13, &func));
}