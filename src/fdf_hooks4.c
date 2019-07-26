/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:02:49 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 00:08:46 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_scale_up(t_fdf *glb)
{
	glb->wld.x_change += 50;
	glb->wld.y_change += 50;
	glb->wld.x_offset = (glb->wld.x_change / (glb->read.col - 1));
	glb->wld.y_offset = (glb->wld.y_change / (glb->read.row - 1));
	set_scaled(glb);
	rotate_points(glb);
	mlx_clear_window(glb->mlx, glb->mlx_win);
	draw_map(glb);
}

void	map_scale_down(t_fdf *glb)
{
	glb->wld.x_change -= 50;
	glb->wld.y_change -= 50;
	glb->wld.x_offset = (glb->wld.x_change / (glb->read.col - 1));
	glb->wld.y_offset = (glb->wld.y_change / (glb->read.row - 1));
	set_scaled(glb);
	rotate_points(glb);
	mlx_clear_window(glb->mlx, glb->mlx_win);
	draw_map(glb);
}
