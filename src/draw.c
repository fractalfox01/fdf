/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:33:39 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/26 10:08:21 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	draw_x(t_global *glbl, int p)
{
	int			x;
	int			y;
	int			err;
	int			e2;
	t_points	*fdf;
	int			p_start;

	p_start = p;
	fdf = glbl->fdf;
	x = glbl->fdf->tab[p][0];
	y = glbl->fdf->tab[p][1];
	DX = abs(glbl->fdf->tab[(p + 1)][1] - x);
	XINC = (glbl->fdf->tab[p][0] < glbl->fdf->tab[p + 1][0]) ? 1 : -1;
	DY = abs(glbl->fdf->tab[p + 1][1] - glbl->fdf->tab[p][1]);
	YINC = (glbl->fdf->tab[p][1] < glbl->fdf->tab[p + 1][1]) ? 1 : -1;
	err = (DX > DY ? DX : -DY) / 2;
	while ((p - p_start) < (fdf->width - 1))
	{
		while (x < fdf->tab[p + 1][1])
		{
			mlx_pixel_put(MLX_P, MLX_W, x + OFFSET_X, y + OFFSET_Y, 0xfffff);
			if (x == glbl->fdf->tab[p + 1][0] && y == glbl->fdf->tab[p + 1][1])
				break ;
			e2 = err;
			if (e2 > -DX)
			{
				err -= DX;
				x += YINC;
			}
			else if (e2 < DY)
			{
				err += DY;
				x -= XINC;
			}
		}
		printf("done: %d\n", p);
		p++;
	}
}

void	draw_y(t_global *glbl, int p)
{
	int			x;
	int			y;
	int			err;
	int			e2;
	t_points	*fdf;
	int			p_start;

	p_start = p;
	fdf = glbl->fdf;
	x = glbl->fdf->tab[p][0];
	y = glbl->fdf->tab[p][1];
	DX = abs(glbl->fdf->tab[(p + 1)][1] - x);
	XINC = (glbl->fdf->tab[p][0] < glbl->fdf->tab[p + 1][0]) ? 1 : -1;
	DY = abs(glbl->fdf->tab[p + 1][1] - glbl->fdf->tab[p][1]);
	YINC = (glbl->fdf->tab[p][1] < glbl->fdf->tab[p + 1][1]) ? 1 : -1;
	err = (DX > DY ? DX : -DY) / 2;
	while ((p - p_start) < (fdf->width - 1))
	{
		while (y < fdf->tab[p + fdf->width][0])
		{
			mlx_pixel_put(MLX_P, MLX_W, x + OFFSET_X, y + OFFSET_Y, 0xfffff);
			if (x == glbl->fdf->tab[p + fdf->width][0] && y == glbl->fdf->tab[p + fdf->width][1])
				break ;
			e2 = err;
			if (e2 > -DX)
			{
				err -= DX;
				x += XINC;
				y += YINC;
			}
			else if (e2 < DY)
			{
				err -= DY;
				y += YINC;
			}
		}
		printf("done: %d\n", p);
		p++;
	}
}

void	draw_points(t_global *glbl)
{
	int	a;

	a = 0;
	while (a < glbl->fdf->total)
	{
		draw_x(glbl, a);
		draw_y(glbl, a);
		a += glbl->fdf->width;
		mlx_do_sync(glbl->mlx);
	}
}