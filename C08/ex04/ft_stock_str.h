/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:17:11 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/25 16:45:52 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STOCK_STR_H
#define _FT_STOCK_STR_H

typedef struct s_stock_str
{
	int	size;
	char	*str;
	char	*copy;
}	t_stock_str;

int	ft_strlen(char *str);

char	*ft_strdup(char *src);

struct s_stock_str *ft_strs_to_tab(int ac, char **av);

void	ft_putstr(char *str);

void	ft_putnbr(int nb);

void	ft_show_tab(struct s_stock_str *par);

#endif
