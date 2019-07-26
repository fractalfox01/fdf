/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:02:44 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 00:08:16 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_rotate_left_down(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	map_rotate_left(glb);
	map_rotate_down(glb);
}

void	map_rotate_right_down(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	map_rotate_right(glb);
	map_rotate_down(glb);
}

void	map_rotate_right_up(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	map_rotate_right(glb);
	map_rotate_up(glb);
}

void	map_rotate_left_up(t_fdf *glb)
{
	mlx_clear_window(glb->mlx, glb->mlx_win);
	map_rotate_left(glb);
	map_rotate_up(glb);
}
