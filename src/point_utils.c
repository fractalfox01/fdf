/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:39:59 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/25 12:15:47 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void    scale_points(t_global *glbl, int i)
{
    int **tab;
    int a;
    int b;

    a = 0;
    b = i;
    tab = glbl->fdf->tab;
    glbl->fdf->dx = 0;
    glbl->fdf->dy = 0;
    glbl->fdf->x = 0;
    glbl->fdf->y = 0;
    glbl->fdf->step = 0;
    glbl->x_scale = ((WIN_W - 200) / 2) / glbl->fdf->width;
    glbl->y_scale = ((WIN_H - 200) / 2) / glbl->fdf->height;
    glbl->fdf->xinc = glbl->x_scale;
    glbl->fdf->yinc = glbl->y_scale;
    while (i < glbl->fdf->total)
    {
        tab[i][0] *= glbl->x_scale;
        tab[i][1] *= glbl->y_scale;
        i++;
    }
}