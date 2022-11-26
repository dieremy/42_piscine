/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:16:24 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/17 09:46:57 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(int i, int j)
{
	int ai;
	int aj;
	int bi;
	int bj;

	ai = ((i / 10) + 48);
	aj = ((i % 10) + 48);
	bi = ((j / 10) + 48);
	bj = ((j % 10) + 48);
	write(1, &ai, 1);
	write(1, &aj, 1);
	write(1, " ", 1);
	write(1, &bi, 1);
	write(1, &bj, 1);
	if (i == 98 && j == 99)
		return ;
	else
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int i;
	int j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			print_num(i, j);
			j++;
		}
		i++;
	}
}
