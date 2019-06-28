/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:39:59 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/27 18:41:47 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void    scale_points(t_global *glb, int i)
{
    int **tab;
    int a;
    int b;

    a = 0;
    b = i;
    tab = glb->fdf->tab;
    glb->offset_x = 50;
    glb->offset_y = 50;
    glb->fdf->dx = 0;
    glb->fdf->dy = 0;
    glb->fdf->x = 0;
    glb->fdf->y = 0;
    glb->fdf->xinc = 0;
    glb->fdf->yinc = 0;
    glb->rot_x = 0;
    glb->rot_y = 0;
    glb->x_scale = (WORLD_W - 100) / (glb->fdf->width - 1);
    glb->y_scale = (WORLD_H - 100) / (glb->fdf->height - 1);
    if (glb->x_scale > glb->y_scale)
    {
        a = glb->x_scale;
        glb->x_scale = glb->y_scale;
        glb->y_scale = a;
    }
    glb->fdf->xstep = glb->x_scale;
    glb->fdf->ystep = glb->y_scale;
    while (i < glb->fdf->total)
    {
        tab[i][0] *= glb->x_scale;
        tab[i][1] *= glb->y_scale;
        i++;
    }
}