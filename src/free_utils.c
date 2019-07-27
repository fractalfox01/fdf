/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:23:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/27 00:17:36 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		skip_digit(char *line)
{
	int i;

	i = 0;
	while (ft_isdigit(line[i]))
		i++;
	return (i);
}

void	swap_points(int *a1, int *a2)
{
	int	tmp;

	tmp = 0;
	if (a2 < a1)
	{
		tmp = *a2;
		*a2 = *a1;
		*a1 = tmp;
	}
}

void	free_map(t_fdf *glb)
{
	int i;

	i = 0;
	if (glb)
	{
		ft_putstr("Freeing maps...\n");
		while (i < glb->read.row)
		{
			free((void *)glb->map.tab[i]);
			free((void *)glb->map.s_tab[i]);
			i++;
		}
		ft_memdel((void **)glb->map.tab);
		ft_memdel((void **)glb->map.s_tab);
	}
}
