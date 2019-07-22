/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:02:58 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/21 13:31:19 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    map_rotate_left(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Rotating Left...\n");
    set_scaled(glb);
    glb->cam.rotate_x -= 1;
    rotate_points(glb);
    draw_map(glb);
}

void    map_rotate_right(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Rotating Right...\n");
    set_scaled(glb);
    glb->cam.rotate_x += 1;
    rotate_points(glb);
    draw_map(glb);
}

void    map_rotate_up(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Rotating Up...\n");
    set_scaled(glb);
    glb->cam.rotate_y += 1;
    rotate_points(glb);
    draw_map(glb);
}

void    map_rotate_down(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Rotating Up...\n");
    set_scaled(glb);
    glb->cam.rotate_y -= 1;
    rotate_points(glb);
    draw_map(glb);
}

void    map_reset(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Resetting Map...\n");
    draw_map(glb);
}

void    map_scale_up(t_fdf *glb)
{
    ft_putstr("Scaling Map Up...\n");
    glb->wld.x_change += 50;
    glb->wld.y_change += 50;
    glb->wld.x_offset = (glb->wld.x_change / (glb->read.col - 1));
    glb->wld.y_offset = (glb->wld.y_change / (glb->read.row - 1));
    set_scaled(glb);
    rotate_points(glb);
    mlx_clear_window(glb->mlx, glb->mlx_win);
    draw_map(glb);
}

void    map_scale_down(t_fdf *glb)
{
    ft_putstr("Scaling Map down...\n");
    glb->wld.x_change -= 50;
    glb->wld.y_change -= 50;
    glb->wld.x_offset = (glb->wld.x_change / (glb->read.col - 1));
    glb->wld.y_offset = (glb->wld.y_change / (glb->read.row - 1));
    set_scaled(glb);
    rotate_points(glb);
    mlx_clear_window(glb->mlx, glb->mlx_win);
    draw_map(glb);
}