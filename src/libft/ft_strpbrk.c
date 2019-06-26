/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:08:05 by tvandivi          #+#    #+#             */
/*   Updated: 2019/03/25 13:59:18 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *str1, const char *str2)
{
	int		i;
	int		j;
	int		len;
	char	*ret;

	i = 0;
	j = 0;
	len = ft_strlen((char *)str1);
	while (i < len)
	{
		ret = (char *)str1;
		while (str2[j] != '\0')
		{
			if (*ret == str2[j])
				return (ret);
			j++;
		}
		j = 0;
		str1++;
		i++;
	}
	return (NULL);
}
