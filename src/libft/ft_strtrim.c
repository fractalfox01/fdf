/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:22:49 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/22 15:47:46 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		start;
	int		end;
	int		i;
	size_t	size;

	if (s)
	{
		i = 0;
		while (ft_whitespace(s[i]) && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != '\0')
			i++;
		i -= 1;
		while (ft_whitespace(s[i]) && i > start)
			i--;
		i++;
		end = i;
		size = end - start;
		ret = ft_strsub(s, start, size);
		if (ret)
			return (ret);
	}
	return (NULL);
}
