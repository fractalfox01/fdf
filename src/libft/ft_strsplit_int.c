/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 12:10:33 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/11 12:17:26 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' ' || c == '\r' || c == '\v' || c == '\t' || c == '\r')
		return (1);
	return (0);
}

int	*ft_strsplit_int(char *str)
{
	int	i;
	int	len;
	int	count;
	int	*tab;

	i = 0;
	len = 0;
	count = ft_wordcount(str, ' ');
	tab = (int *)malloc(sizeof(int) * (count + 1));
	while (i < count && *str != '\0')
	{
		len = ft_strxlen(str, ' ');
		tab[i] = ft_atoi(str);
		str += (len + 1);
		i++;
	}
	return (tab);
}
