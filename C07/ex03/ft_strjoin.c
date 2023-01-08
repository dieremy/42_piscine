#include <stdlib.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return i;
}

int	strs_len(int size, char **strs, char sep)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		len += sep;
		i++;
	}
	len -= sep;
	return len;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		x;

	s = (char*)malloc(sizeof(char) * strs_len(size, strs, ft_strlen(sep)) + 1);
	i = 0;
	j = 0;
	while (i < size)
	{
		x = 0;
		while (strs[i][x])
			s[j++] = strs[i][x++];
		x = 0;
		while (sep[x] && i <= size - 1)
			s[j++] = sep[x++];
		i++;
	}
	s[j] = '\0';
	return s;
}

#include <stdio.h>

int main()
{

	char *a[4];
	a[0] = "hello";
	a[1] = "world,";
	a[2] = "how are";
	a[3] = "you?";
	char sep[] = " ";
	char *b = ft_strjoin(4, a, sep);
	printf("%s\n", b);

	return 0;
}