/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:02:58 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/03 12:07:01 by tvandivi         ###   ########.fr       */
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

void    map_rotate_left(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Rotating Left...\n");
    draw_map(glb);
    print_map(glb);
}

void    map_rotate_right(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Rotating Right...\n");
    draw_map(glb);
    print_map(glb);
}

void    map_reset(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Resetting Map...\n");
    draw_map(glb);
    print_map(glb);
}