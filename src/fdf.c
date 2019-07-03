/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:57:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/02 18:23:42 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    init_world(t_fdf *glb, t_world *wld)
{
    wld->s_x = 0;
    wld->s_y = 0;
    wld->x_offset = 0;
    wld->y_offset = 0;
}

void    init_img(t_fdf *glb, t_img *img)
{
    img->data = NULL;
    img->size = glb->read.col;
    img->bpp = 4;
    img->endian = 0;
}

void    init_global(t_fdf *glb)
{
    t_read  *read;
    t_map   *map;

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
    glb->mlx_win = mlx_new_window(glb->mlx, 1280, 720, "FDF - BY TVANDIVI");
    glb->mlx_img = mlx_new_image(glb->mlx, 1280, 720);
    read = &glb->read;
    map = &glb->map;
    read->fd = 0;
    read->row = 0;
    read->col = 0;
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

void    map_up(t_fdf *glb)
{
    mlx_clear_window(glb->mlx, glb->mlx_win);
    ft_putstr("Moving Up...\n");
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

void     passoff(int key, t_fdf *glb)
{
    if (key == 53 || key == 12)     /* Close */
        fdf_close(glb);
    if (key == 123)	                /* LEFT */
        map_left(glb);
    if (key == 124)                 /* RIGHT */
        map_right(glb);
    if (key == 125)                 /* UP */
        map_up(glb);
    if (key == 126)                 /* DOWN */
        map_down(glb);
    if (key == 15)                  /* reset: 'r' */
        map_reset(glb);
    if (key == 14)                  /* rotate left: 'e' */
        map_rotate_left(glb);
    if (key == 13)                  /* rotate right: 'w' */
        map_rotate_right(glb);
    printf("Key: %d\n", key);
}

void    loop_hooks(t_fdf *glb)
{
    mlx_key_hook(glb->mlx_win, passoff, glb);
    mlx_loop(glb->mlx);
}

int fdf(t_fdf *glb, char *filename)
{
    if (glb)
    {
        init_global(glb);
        read_map(glb, filename);
        init_img(glb, &glb->img);
        init_world(glb, &glb->wld);
        draw_map(glb);
        loop_hooks(glb);
    }
    return (0);
}