/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:09:36 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/28 11:13:14 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_atoi(char *str)
{
	int	nbr;
	int	dir;

	nbr = 0;
	dir = 1;
	if (*str == 0)
		return (0);
	while (*str == '\f' || *str == ' ' || *str == '\n' || *str == '\r' \
			|| *str == '\v' || *str == '\t')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			dir *= -1;
		str++;
	}
	while (*str > 47 && *str < 58)
	{
		nbr = nbr * 10 + (*str - 48);
		str++;
	}
	return (nbr * dir);
}
