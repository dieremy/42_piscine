/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:17:11 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/25 16:45:52 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_separator(char c, char *charset)
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
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && check_separator(str[i], charset))
			i++;
		if (str[i] && !check_separator(str[i], charset))
		{
			while (str[i] && !check_separator(str[i], charset))
				i++;
			count++;
		}
	}
	return (count);
}

char	*ft_strdup(char *str, char *charset)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && !check_separator(str[i], charset))
		i++;
	word = (char*)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !check_separator(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**string;

	i = 0;
	string = (char**)malloc(sizeof(char*) * (count_words(str, charset) + 1));
	while (*str)
	{
		while (*str && check_separator(*str, charset))
			str++;
		if (*str && !check_separator(*str, charset))
		{
			string[i] = ft_strdup(str, charset);
			i++;
			while (*str && !check_separator(*str, charset))
				str++;
		}
	}
	string[i] = '\0';
	return (string);
}
