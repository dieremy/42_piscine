/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:42:41 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/26 12:31:05 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	x;

	i = 0;
	j = 0;
	x = 0;
	while (dest[i])
		i++;
	while (src[j])
		j++;
	if (size <= i)
		return (j + size);
	while (src[x] && ((i + x) < (size - 1)))
	{
		dest[i + x] = src[x];
		x++;
	}
	dest[i + x] = '\0';
	return (i + j);
}
