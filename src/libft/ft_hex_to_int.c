/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_to_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:16:47 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/15 12:18:49 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hex_to_int_helper(char *hex, int nbr, int len, int base)
{
	int i;
	int	min;

	i = len;
	min = 0;
	nbr = 0;
	base = 1;
	if (len >= 3 && hex[0] == '0' && hex[1] == 'x')
		min += 2;
	while (--i >= min)
	{
		if (hex[i] >= '0' && hex[i] <= '9')
			nbr += (hex[i] - 48) * base;
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			nbr += (hex[i] - 55) * base;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			nbr += (hex[i] - 87) * base;
		else
			return (0);
		base *= 16;
	}
	return (nbr);
}

int	ft_hex_to_int(char *hex)
{
	int len;

	len = ft_strlen(hex);
	return (ft_hex_to_int_helper(hex, 0, len, 1));
}
