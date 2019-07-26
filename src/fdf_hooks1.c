/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:02:58 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 00:07:05 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_rotate_right(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	set_scaled(glb);
	glb->cam.rotate_y -= 1;
	rotate_points(glb);
	draw_map(glb);
}

void	map_rotate_left(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	set_scaled(glb);
	glb->cam.rotate_y += 1;
	rotate_points(glb);
	draw_map(glb);
}

void	map_rotate_up(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	set_scaled(glb);
	glb->cam.rotate_x += 1;
	rotate_points(glb);
	draw_map(glb);
}

void	map_rotate_down(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	set_scaled(glb);
	glb->cam.rotate_x -= 1;
	rotate_points(glb);
	draw_map(glb);
}

void	map_reset(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	glb->cam.rotate_x = 23;
	glb->cam.rotate_y = -3;
	glb->wld.x_pad = 0;
	glb->wld.y_pad = 0;
	glb->wld.x_change = 1280;
	glb->wld.y_change = 720;
	set_scaled(glb);
	map_scale_up(glb);
}
