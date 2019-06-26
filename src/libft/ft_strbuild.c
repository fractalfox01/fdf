/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbuild.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:34:02 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/23 23:42:56 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strbuild(char **tab, char const *s, char c, int max)
{
	int	b;
	int	i;
	int	len;

	b = 0;
	i = 0;
	len = 0;
	while (b < max && s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
		{
			len = ft_strxlen(&s[i], c);
			tab[b] = ft_strnew(len + 1);
			if (!(tab[b]))
				return (NULL);
			ft_strncpy(tab[b++], &s[i], len);
			i += ft_strxlen(&s[i], c);
		}
		else if (s[i] == '\0' && !(tab[b] = NULL))
			return (tab);
	}
	tab[max] = NULL;
	return (tab);
}
