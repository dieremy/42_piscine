#include <stdlib.h>

int	check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && check_sep(str[i], charset))
			i++;
		if (str[i] && !check_sep(str[i], charset))
			count++;
		while (str[i] && !check_sep(str[i], charset))
			i++;
	}
	return (count);
}

char	*ft_putword(char *str, char *charset)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] && !check_sep(str[i], charset))
		i++;
	if (!(new = (char*)malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (str[i] && !check_sep(str[i], charset))
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	**ft_split(char *str, char *charset)
{
	char **split;
	int	i;
	int	j;

	if (!(split = (char**)malloc(sizeof(char*) * (count_words(str, charset) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (*str)
	{
		while (*str && check_sep(*str, charset))
			str++;
		if (*str && !check_sep(*str, charset))
		{
			split[j] = ft_putword(str, charset);
			j++;
		}
		while (*str && !check_sep(*str, charset))
			str++;
	}
	split[j] = '\0';
	return (split);
}

#include <stdio.h>

int main(int ac, char **av)
{
	int i = 0;
	char** split = ft_split(av[1], av[2]); 
	while (split[i])
	{
		printf("%s\n", split[i]);
		i++;
	}

	return 0;
}