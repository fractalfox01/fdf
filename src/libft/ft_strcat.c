/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:12:22 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/22 15:42:14 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*ptr;
	int		i;
	int		f;
	int		dlen;
	int		s;

	i = (int)sizeof(dest);
	dlen = ft_strlen(dest);
	s = (int)sizeof(src);
	f = 0;
	ptr = dest;
	if (!(*src))
		return (ptr);
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (ptr);
}
