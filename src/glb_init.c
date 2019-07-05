/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glb_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 11:57:59 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/05 12:30:54 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void    init_world(t_fdf *glb, t_world *wld)
{
    wld->s_x = 1380 / 2;
    wld->s_y = 820 / 2;
    wld->win_x = 1280;
    wld->win_y = 720;
    wld->x_margin_min = 50;
    wld->y_margin_min = 50;
    wld->x_margin = 50;
    wld->y_margin = 50;
    wld->x_change = 1280;
    wld->y_change = 720;
    wld->x_offset = (wld->x_change / (glb->read.col - 1));
    wld->y_offset = (wld->y_change / (glb->read.row - 1));
}

void    init_img(t_fdf *glb, t_img *img)
{
    img->data = NULL;
    img->size = glb->read.col;
    img->bpp = 4;
    img->endian = 0;
}

void    init_read(t_fdf *glb)
{
    t_read  *read;

    read = &glb->read;
    read->fd = 0;
    read->row = 0;
    read->col = 0;
    read->origin_x = 0;
    read->origin_y = 0;
}

void    init_map(t_fdf *glb)
{
    t_map   *map;

    map = &glb->map;
    map->co_x = 0;
    map->co_y = 0;
    map->iso = 0;
    map->theta_y = 0;
    map->theta_z = 0;
    map->x_val = 0;
    map->y0 = 0;
    map->y1 = 0;
    map->z0 = 0;
    map->z1 = 0;
    map->zoom = 0;
}

void    init_global(t_fdf *glb)
{
    map_movment *key_tab[8] = { \
        fdf_close, \
        map_down, \
        map_up, \
        map_right, \
        map_left, \
        map_reset, \
        map_rotate_left, \
        map_rotate_right \
    };
    glb->mlx = mlx_init();
    glb->mlx_win = mlx_new_window(glb->mlx, 1380, 820, "FDF - BY TVANDIVI");
    glb->mlx_img = mlx_new_image(glb->mlx, 1380, 820);
    //init_world(glb, &glb->wld);
    init_read(glb);
    init_map(glb);
}
