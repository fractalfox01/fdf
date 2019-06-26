/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 20:23:51 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/17 23:08:53 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = dest;
	if (!(*src))
		return (ptr);
	while (*dest != '\0')
		dest++;
	while (*src != '\0' && i++ < (int)n)
	{
		*dest++ = *src++;
	}
	*dest = '\0';
	return (ptr);
}
