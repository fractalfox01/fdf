/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:33:39 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/27 12:01:17 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	set_def(t_global *glb, int p)
{
	t_points	*fdf;

	fdf = glb->fdf;
	DX = abs(fdf->tab[(p + 1)][1] - glb->vec->x);
	XINC = (fdf->tab[p][0] < fdf->tab[p + 1][0]) ? 1 : -1;
	DY = abs(fdf->tab[p + 1][1] - fdf->tab[p][1]);
	YINC = (fdf->tab[p][1] < fdf->tab[p + 1][1]) ? 1 : -1;
}

void	set_vec(t_global *glb, int p)
{
	t_vec		*vec;
	t_points	*fdf;

	fdf = glb->fdf;
	vec = glb->vec;
	vec->x = glb->fdf->tab[p][0];
	vec->y = glb->fdf->tab[p][1];
	vec->err = (DX > DY ? DX : -DY) / 2;
}

void	reverse_x(t_global *glb, int p)
{
	t_points	*fdf;
	t_vec		*vec;
	int			x;
	int			x0;
	int			y;

	x0 = 0;
	fdf = glb->fdf;
	vec = glb->vec;
	vec->p_start = p;
	while (((p - vec->p_start) + 1) < (fdf->width))
	{
		x0 = fdf->tab[p][0];
		x = fdf->tab[p][1];
		y = fdf->tab[p + 1][1];
		if (x0 < y)
		{
			while (x++ < y)
			{
				mlx_pixel_put(glb->mlx, glb->mlx_win, (x0++ + 50), (fdf->tab[p][0] + 50) , 0xfffff);
			}
		}
		else if (x0 == y)
		{
			while (x < x0)
			{
				mlx_pixel_put(glb->mlx, glb->mlx_win, (x++ + 50), (x0 + 50), 0xfffff);
			}
		}
		//mlx_do_sync(glb->mlx);
		p++;
	}
}

void	reverse_y(t_global *glb, int p)
{
	t_points	*fdf;
	t_vec		*vec;
	int			x;
	int			x0;
	int			y;

	x0 = 0;
	fdf = glb->fdf;
	vec = glb->vec;
	vec->p_start = p;
	while (((p - vec->p_start) + 1) < (fdf->width))
	{
		x0 = fdf->tab[p][1];
		x = fdf->tab[p][0];
		y = fdf->tab[p + fdf->width][0];
		if (x < y)
		{
			while (x++ < y)
			{
				mlx_pixel_put(glb->mlx, glb->mlx_win, (fdf->tab[p][0] + 50), (x0++ + 50), 0xfffff);
			}
		}
		//mlx_do_sync(glb->mlx);
		p++;
	}
}




void	draw_x(t_global *glb, int p)
{
	t_points	*fdf;
	t_vec		*vec;
	int			x;
	int			x0;
	int			y;

	x0 = 0;
	fdf = glb->fdf;
	vec = glb->vec;
	vec->p_start = p;
	while (((p - vec->p_start) + 1) < (fdf->width))
	{
		x0 = fdf->tab[p][0];
		x = fdf->tab[p][1];
		y = fdf->tab[p + 1][1];
		if (x0 < y)
			while (x++ < y)
				mlx_pixel_put(glb->mlx, glb->mlx_win, (x + glb->offset_x), (x0 + glb->offset_y), 0xfffff);
		else if (x0 >= y)
			while (x < x0)
				mlx_pixel_put(glb->mlx, glb->mlx_win, (x++ + glb->offset_x), (x0 + glb->offset_y), 0xfffff);
		p++;
	}
}

void	draw_y(t_global *glb, int p)
{
	t_points	*fdf;
	t_vec		*vec;
	int			x;
	int			x0;
	int			y;

	x0 = 0;
	fdf = glb->fdf;
	vec = glb->vec;
	vec->p_start = p;
	if ((p + fdf->width) < (fdf->total))
	{
		while ((p + fdf->width) < (fdf->total))
		{
			x0 = fdf->tab[p][1];
			x = fdf->tab[p][0];
			y = fdf->tab[p + fdf->width][0];
			if (x < y)
				while (x++ < y)
					mlx_pixel_put(glb->mlx, glb->mlx_win, (x0 + glb->offset_x), (x + glb->offset_y), 0xfffff);
			p++;
		}
	}
}

void	vec_init(t_vec *vec)
{
	vec->x = 0;
	vec->y = 0;
	vec->err = 0;
	vec->e2 = 0;
	vec->p_start = 0;
}

void	equal_draw(t_global *glb, int a)
{
	draw_x(glb, a);
	draw_y(glb, a);
}

void	reverse_draw(t_global *glb, int a)
{
	reverse_x(glb, a);
	reverse_y(glb, a);
}

void	draw_points(t_global *glb)
{
	int		a;
	int		i;
	t_vec	vec;
	t_points	*fdf;
	
	a = 0;
	i = 0;
	vec_init(&vec);
	glb->vec = &vec;
	fdf = glb->fdf;
	//console_print_points(*fdf);
	while (a < glb->fdf->total)
	{
		if (fdf->width == fdf->height)
			equal_draw(glb, a);
		if (fdf->width > fdf->height)
			equal_draw(glb, a);
		if (fdf->width < fdf->height)
			equal_draw(glb, a);
		//glb->fdf->y = glb->y_scale * ++i;
		//glb->fdf->ystep = 0;
		a += glb->fdf->width;
		//mlx_do_sync(glb->mlx);
	}
	mlx_do_sync(glb->mlx);
}