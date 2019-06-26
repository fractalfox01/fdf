/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 22:51:31 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/22 15:47:35 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sptr;
	char	*tmp;
	int		i;

	if (s)
	{
		i = 0;
		sptr = (char *)s;
		tmp = ft_memalloc(len + 1);
		if (tmp)
		{
			while (i < (int)len)
			{
				tmp[i++] = sptr[start++];
			}
			tmp[i] = '\0';
			return (tmp);
		}
	}
	return (NULL);
}
