/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:05:54 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/05 13:21:50 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    fdf_close(t_fdf *glb)
{
    ft_putstr("Closing Program...\n");
    mlx_destroy_window(glb->mlx, glb->mlx_win);
    print_map(glb);
    free_map(glb);
    ft_putstr("finished freeing..\n");
    exit(0);
}

void    map_left(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Moving Left...\n");
    glb->wld.x_margin -= 10;
    set_scaled(glb, 0);
    draw_map(glb);
    //print_map(glb);
}

void    map_right(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Moving Right...\n");
    glb->wld.x_margin += 10;
    set_scaled(glb, 0);
    draw_map(glb);
    //print_map(glb);
}

void    map_down(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Moving Down...\n");
    glb->wld.y_margin -= 10;
    set_scaled(glb, 0);
    draw_map(glb);
    //print_map(glb);
}

void    map_up(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Moving Up...\n");
    glb->wld.y_margin += 10;
    set_scaled(glb, 0);
    draw_map(glb);
    //print_map(glb);
}