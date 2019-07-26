/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 00:16:56 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/25 22:55:04 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_x(t_fdf *glb, float p1[3], float p2[3])
{
	int	x1;
	int	x2;
	int	sum;
	int	j;
	int	m;

	sum = 0;
	x1 = p1[0];
	x2 = p2[0];
	if (x2 < x1)
		swap_points(&x1, &x2);
	glb->map.dx = (x2 - x1);
	j = p1[1];
	while (x1 < x2)
	{
		sum += p2[1] - p1[1];
		m = sum / glb->map.dx;
		changer(m, &sum, glb->map.dx, &j);
		x1 += 1;
		glb->map.x1 = x1 + glb->wld.s_x + glb->wld.x_pad;
		glb->map.y1 = j + glb->wld.s_y + glb->wld.y_pad;
		mlx_pixel_put(glb->mlx, glb->mlx_win, glb->map.x1, glb->map.y1, H_GRN);
	}
}

void	draw_y(t_fdf *glb, float p1[3], float p2[3])
{
	int	y1;
	int	y2;
	int	sum;
	int	j;
	int	m;

	y1 = p1[1];
	y2 = p2[1];
	sum = 0;
	if (y2 < y1)
		swap_points(&y1, &y2);
	glb->map.dy = y2 - y1;
	j = p1[0];
	while (y1 < y2)
	{
		sum += p2[0] - p1[0];
		m = sum / glb->map.dy;
		changer(m, &sum, glb->map.dy, &j);
		y1 += 1;
		glb->map.x1 = j + glb->wld.s_x + glb->wld.x_pad;
		glb->map.y1 = y1 + glb->wld.s_y + glb->wld.y_pad;
		mlx_pixel_put(glb->mlx, glb->mlx_win, glb->map.x1, glb->map.y1, Q_GRN);
	}
}

void	connect_x(t_fdf *glb, int i, int j)
{
	while (i < glb->read.row)
	{
		while ((j + 5) < (glb->read.col * 3))
		{
			glb->map.p1[0] = glb->map.s_tab[i][j];
			glb->map.p1[1] = glb->map.s_tab[i][j + 1];
			glb->map.p1[2] = glb->map.s_tab[i][j + 2];
			glb->map.p2[0] = glb->map.s_tab[i][j + 3];
			glb->map.p2[1] = glb->map.s_tab[i][j + 4];
			glb->map.p2[2] = glb->map.s_tab[i][j + 5];
			draw_x(glb, glb->map.p1, glb->map.p2);
			j += 3;
		}
		j = 0;
		i++;
	}
}

void	connect_y(t_fdf *glb, int i, int j)
{
	while (i + 1 < glb->read.row)
	{
		while ((j + 2) < glb->read.col * 3)
		{
			glb->map.p1[0] = glb->map.s_tab[i][j];
			glb->map.p1[1] = glb->map.s_tab[i][j + 1];
			glb->map.p1[2] = glb->map.s_tab[i][j + 2];
			glb->map.p2[0] = glb->map.s_tab[i + 1][j];
			glb->map.p2[1] = glb->map.s_tab[i + 1][j + 1];
			glb->map.p2[2] = glb->map.s_tab[i + 1][j + 2];
			draw_y(glb, glb->map.p1, glb->map.p2);
			j += 3;
		}
		j = 0;
		i++;
	}
}

void	draw_map(t_fdf *glb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (glb)
	{
		connect_x(glb, i, j);
		i = 0;
		j = 0;
		connect_y(glb, i, j);
		mlx_do_sync(glb->mlx);
		return ;
	}
}
