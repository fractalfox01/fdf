/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:57:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 00:05:50 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	passoff_1(int key, t_fdf *glb)
{
	if (key == 53 || key == 12)
		fdf_close(glb);
	else if (key == 15)
		map_reset(glb);
	else if (key == 123)
		map_left(glb);
	else if (key == 124)
		map_right(glb);
	else if (key == 126)
		map_up(glb);
	else if (key == 125)
		map_down(glb);
	else if (key == 91)
		map_rotate_up(glb);
	else if (key == 84)
		map_rotate_down(glb);
}

void	passoff_2(int key, t_fdf *glb)
{
	if (key == 88)
		map_rotate_left(glb);
	else if (key == 86)
		map_rotate_right(glb);
	else if (key == 11)
		map_scale_up(glb);
	else if (key == 9)
		map_scale_down(glb);
	else if (key == 92)
		map_rotate_right_up(glb);
	else if (key == 85)
		map_rotate_right_down(glb);
	else if (key == 83)
		map_rotate_left_down(glb);
	else if (key == 89)
		map_rotate_left_up(glb);
}

int		key_router(int key, t_fdf *glb)
{
	passoff_1(key, glb);
	passoff_2(key, glb);
	return (1);
}

void	loop_hooks(t_fdf *glb)
{
	mlx_key_hook(glb->mlx_win, key_router, glb);
	mlx_loop(glb->mlx);
}

int		fdf(t_fdf *glb, char *filename)
{
	if (glb)
	{
		init_global(glb, filename);
		read_map(glb, filename);
		init_camera(glb, &glb->cam);
		init_world(glb, &glb->wld);
		set_scaled(glb);
		rotate_points(glb);
		draw_map(glb);
		loop_hooks(glb);
		free_map(glb);
	}
	return (0);
}
