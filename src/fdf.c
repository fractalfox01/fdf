/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 13:57:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/03 12:03:45 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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