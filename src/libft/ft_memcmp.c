/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 12:11:12 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/22 17:22:41 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*uc1;
	unsigned char	*uc2;
	int				nb1;
	int				nb2;

	nb1 = 0;
	nb2 = 0;
	uc1 = (unsigned char *)s1;
	uc2 = (unsigned char *)s2;
	while (n > 0)
	{
		if (!(*uc1 == *uc2))
		{
			nb1 += *uc1;
			nb2 += *uc2;
			break ;
		}
		uc1++;
		uc2++;
		n--;
	}
	return (nb1 - nb2);
}
