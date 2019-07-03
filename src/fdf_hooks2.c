/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hooks2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 12:05:54 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/03 12:06:19 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    map_left(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Moving Left...\n");
    draw_map(glb);
    print_map(glb);
}

void    map_right(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Moving Right...\n");
    draw_map(glb);
    print_map(glb);
}

void    map_down(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Moving Down...\n");
    draw_map(glb);
    print_map(glb);
}

void    map_up(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Moving Up...\n");
    draw_map(glb);
    print_map(glb);
}