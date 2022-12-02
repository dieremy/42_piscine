/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:17:11 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/25 16:45:52 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
		return (0);
	array = (int*)malloc(sizeof(int) * (max - min));
	if (!array)
		return (0);
	i = 0;
	while (i < (max - min))
	{
		array[i] = min++;
		i++;
	}
	//array[i] = '\0';
	return (array);
}

int main()
{
	int *a = ft_range(13, 39);
	for (int i = 0; i < 26; i++)
		printf("%d\n", a[i]);
}