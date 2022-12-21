#include <unistd.h>
#include <fcntl.h>

int	ft_display(char *file)
{
	int		f;
	int		r;
	char	c;

	f = open(file, 0);
	if (f == -1)
		return (0);
	while ((r = read(f, &c, 1)))
	{
		if (r == -1)
			return (0);
		write(1, &c, 1);
	}
	close(f);
	return (1);
}

int main(int ac, char **av)
{
	if (ac == 1)
		write(1, "File name missing.\n", 19);
	else if (ac > 2)
		write(1, "Too many arguments.\n", 20);
	else
	{
		if (!ft_display(av[1]))
			write(1, "Cannot read file.\n", 16);
	}
}