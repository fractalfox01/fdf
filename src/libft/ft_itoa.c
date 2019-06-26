/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 15:38:18 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/27 11:11:47 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_value(char *ptr, long nbr, long len, long b)
{
	char	*cat;
	long	rem;

	rem = 1;
	cat = "-2147483648";
	if (nbr == -2147483648)
	{
		b = -1;
		ptr = ft_strnew(12);
		while (++b < 11)
			ptr[b] = cat[b];
		return (ptr);
	}
	while (len > 0)
	{
		ptr[b++] = (nbr / ft_power(len, 10)) + 48;
		rem = (nbr % ft_power(len, 10));
		nbr -= ft_power(len, 10) * (nbr / ft_power(len, 10));
		len--;
	}
	return (ptr);
}

char		*ft_itoa(int n)
{
	long	nbr;
	char	*ptr;
	long	len;
	long	b;
	long	tmp;

	len = 1;
	b = 0;
	nbr = (long)n;
	if ((n < 0) && n != -2147483648)
		nbr = -nbr;
	tmp = nbr;
	while (tmp >= 10)
		tmp = (nbr / ft_power(len++, 10));
	if (len != 1)
		len--;
	ptr = ft_strnew(len + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
		ptr[b++] = '-';
	if (nbr == 0 && (ptr[b] = '0'))
		return (ptr);
	return (find_value(ptr, nbr, len, b));
}
