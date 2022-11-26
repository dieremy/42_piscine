/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 16:13:05 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/19 16:15:00 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') 
			|| (str[i] >= 'A' && str[i] <= 'Z')) 
			i++;
		else
			return (0);
	}
	return (1);
}
