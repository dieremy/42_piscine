#include <unistd.h>

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
void	ft_putnbr(int n)
{
	char	x;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		ft_putnbr(n);
	}
	else if (n < 10)
	{
		x = n + 48;
		write(1, &x, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int main()
{
	int new[] = {21, 432, 78, 90, 168};
	ft_foreach(new, 5, &ft_putnbr);
}*/