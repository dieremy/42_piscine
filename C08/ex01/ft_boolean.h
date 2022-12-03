/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robegarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 14:17:11 by robegarc          #+#    #+#             */
/*   Updated: 2022/10/25 16:45:52 by robegarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_BOOLEAN_H

#define _FT_BOOLEAN_H

#include <unistd.h>

#define EVEN_MSG "I have an even number of arguments.\n"

#define ODD_MSG "I have an odd number of arguments.\n"

#define SUCCESS 0

#define TRUE 1

#define FALSE 0

#define EVEN(number) (number % 2 == 0)

typedef int t_bool;

#endif
