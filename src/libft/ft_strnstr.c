/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 00:27:08 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/26 21:42:22 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_strlen((char *)s2);
	if (!s1)
	{
		if (s1[1] == '\0')
			return ("Segfault");
	}
	if (!s2)
		return ((char *)s1);
	while (((i + j) < n + 1) && s1[i])
	{
		if ((ft_strncmp(&s1[i], s2, j)) == 0)
		{
			return ((char *)&s1[i]);
		}
		i++;
	}
	return (NULL);
}
