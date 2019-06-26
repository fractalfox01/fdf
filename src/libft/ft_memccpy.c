/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:10:55 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/22 15:37:35 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*d;
	const char	*s;
	void		*p;
	void		*r;

	d = (char *)dest;
	s = (char *)src;
	p = ft_memchr(src, (char)c, n);
	if (!n)
		return (NULL);
	if (p != NULL)
	{
		ft_memcpy(d, s, p - src + 1);
		r = ft_memchr(d, (char)c, n);
		return ((void *)r + 1);
	}
	ft_memcpy(d, s, n);
	return (NULL);
}
