/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:17:11 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/25 16:45:52 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;
	int *array;

	if (min >= max)
		return 0;
	size = max - min;
	array = (int*)malloc(sizeof(int) * size);
	if (!array)
		return -1;
	*range = array;
	i = 0;
	while (i < size)
	{
		array[i] = min++;
		i++;
	}
	return size;
}

int main()
{
	int *A;
	int size = ft_ultimate_range(&A, 13, 39);
	for (int i = 0; i < size; i++)
		printf("%d\n", A[i]);
}
