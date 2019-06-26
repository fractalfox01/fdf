/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 01:24:21 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/20 18:23:08 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		k;
	char	*ptr;
	size_t	i;
	size_t	len1;
	size_t	len2;

	if (s1 && s2)
	{
		i = -1;
		k = 0;
		len1 = ft_strlen((char *)s1);
		len2 = ft_strlen((char *)s2);
		ptr = ft_strnew((len1 + len2) + 1);
		if (ptr)
		{
			while (++i < len1)
				ptr[i] = s1[i];
			while (i < (len1 + len2))
				ptr[i++] = s2[k++];
			ptr[i] = '\0';
		}
		return (ptr);
	}
	return (NULL);
}
