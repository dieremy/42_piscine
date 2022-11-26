/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 09:16:24 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/17 09:46:57 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_num(int i, int j, int x)
{
	write(1, &i, 1);
	write(1, &j, 1);
	write(1, &x, 1);
	if (i != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int x;

	i = '0';
	while (i <= '7')
	{
		j = i + 1;
		while (j <= '8')
		{
			x = j + 1;
			while (x <= '9')
			{
				print_num(i, j, x);
				x++;
			}
			j++;
		}
		i++;
	}	
}
