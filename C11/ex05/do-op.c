#include <unistd.h>

void ft_putn(int n)
{
	char	x;

	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		ft_putn(n);
	}
	else if (n < 10)
	{
		x = n + 48;
		write(1, &x, 1);
	}
	else
	{
		ft_putn(n / 10);
		ft_putn(n % 10);
	}
}

int	ft_atoi(char *s)
{
	int	sign;
	int	r;

	sign = 1;
	r = 0;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+')
		s++;
	else if (*s == '-')
	{
		sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		r = r * 10 + *s - 48;
		s++;
	}
	return (sign * r);
}

void	do_op(int x, char s, int y)
{
	int r;

	r = 0;
	if (s == '-')
		r = x - y;
	if (s == '+')
		r = x + y;
	if (s == '*')
		r = x * y;
	if (s == '/' && (x > 0))
	{
		if (y <= 0)
			write(1, "Stop : division by zero\n", 24);
		r = x / y;
	}
	if (s == '%' && (x > 0))
	{
		if (y <= 0)
			write(1, "Stop : modulo by zero\n", 22);
		r = x % y;
	}
	ft_putn(r);
}

int main(int ac, char **av)
{
	do_op(ft_atoi(av[1]), av[2][0], ft_atoi(av[3]));
	write(1, "\n", 1);
}