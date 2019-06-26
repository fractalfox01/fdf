/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 13:33:43 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/21 23:50:44 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_wordcount(char *str, char c)
{
	int		nbr;
	int		flag;
	int		i;

	i = 0;
	flag = 1;
	nbr = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i] != '\0')
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			if (flag == 1)
			{
				flag = 0;
				nbr++;
			}
			i++;
		}
		flag = 1;
	}
	if (nbr)
		return (nbr);
	return (-1);
}
