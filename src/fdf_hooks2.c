/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:05:54 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 22:24:24 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_close(t_fdf *glb)
{
	ft_putstr("Closing Program...\n");
	mlx_destroy_window(glb->mlx, glb->mlx_win);
	free_map(glb);
	system("leaks fdf");
	exit(0);
}

void	map_left(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	glb->wld.x_pad -= 10;
	draw_map(glb);
}

void	map_right(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	glb->wld.x_pad += 10;
	draw_map(glb);
}

void	map_down(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	glb->wld.y_pad += 10;
	draw_map(glb);
}

void	map_up(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	glb->wld.y_pad -= 10;
	draw_map(glb);
}
