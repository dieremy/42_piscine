/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:17:11 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/25 16:45:52 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	long	out;
	long	n;
	
	n = nb;
	if (n <= 0)
		return (0);
	if (n == 1)
		return (1);
	out = 2
	if (n >= 2)
	{
		while ((out * out) <= n)
		{
			if ((out * out) == n)
				return (out);
			out++;
		}
	}
	return (0);
}