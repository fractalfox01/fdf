/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 00:16:38 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/25 17:56:29 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_sign(int nbr)
{
	if (nbr < 0)
		return (-1);
	return (1);
}

int		get_color(float p1[3], float p2[3], int x1, int x2)
{
	float	x;
	float	size;

	if (x1 < x2)
	{
		x = x1;
		size = (float)x2 - x1;
		if (x <= (size * .2))
			return (RED);
		if (x > (size * .2) && x <= (size * .4))
			return (RED - GREEN);
		if (x > (size * .4) && x <= (size * .6))
			return (16776960);
		if (x > (size * .6) && x <= (size * .8))
			return (GREEN + GREEN);
		else
		{
			return (GREEN);
		}
	}
	return (GREEN);
}

void	add_rotation(t_fdf *glb, int i, int j)
{
	int		y;
	float	ang_x;
	float	ang_y;

	ang_x = (glb->cam.rotate_x * M_PI) / 180;
	ang_y = (glb->cam.rotate_y * M_PI) / 180;
	y = glb->map.s_tab[i][j + 1];
	glb->map.s_tab[i][j + 1] = (cos(ang_x) * y) - (sin(ang_x) * \
		(glb->map.s_tab[i][j + 2]));
	glb->map.s_tab[i][j + 2] = (sin(ang_x) * y) + (cos(ang_x) * \
		(glb->map.s_tab[i][j + 2]));
	glb->map.s_tab[i][j] = (cos(ang_y) * glb->map.s_tab[i][j]) \
		- (sin(ang_y) * glb->map.s_tab[i][j + 2]);
}

void	rotate_points(t_fdf *glb)
{
	int		i;
	int		j;
	float	ang_x;
	float	ang_y;
	int		y;

	i = 0;
	j = 0;
	while (i < glb->read.row)
	{
		while (j < glb->read.col * 3)
		{
			add_rotation(glb, i, j);
			j += 3;
		}
		j = 0;
		i++;
	}
}

void	changer(int m, int *sum, int d, int *j)
{
	if (m >= 1)
	{
		*sum = *sum - d;
		*j = *j + 1;
	}
	else if (m < 0)
	{
		*sum = *sum + d;
		*j = *j - 1;
	}
}
