/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 23:06:06 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/22 15:45:43 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	int	i;

	i = ft_strlen((char *)src);
	if (i > (int)n)
	{
		return (ft_memcpy(dst, src, n));
	}
	else if (i != (int)n)
	{
		ft_memset(dst + i, '\0', n - i);
		return (ft_memcpy(dst, src, i));
	}
	return (ft_memcpy(dst, src, n));
}
