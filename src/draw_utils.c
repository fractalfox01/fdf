/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:34:58 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/05 13:18:36 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    draw_y(t_fdf *glb, int p)
{
    int y;
    int y2;
    int x;
    int a;
    
    if ((p + (glb->read.col * 3) + 1) < ((glb->read.col * glb->read.row) * 3))
    {
        x = glb->map.scaled_tab[p];
        y = glb->map.scaled_tab[p + 1];
        a = (p + (glb->read.col * 3) + 1);
        y2 = glb->map.scaled_tab[a];
        while (y < y2 && ((x <= glb->wld.win_x && x >= glb->wld.x_margin_min) && (y <= glb->wld.win_y && y >= glb->wld.y_margin_min)))
        {
            if (y >= glb->wld.win_y)
                y++;
            else
            {
                mlx_pixel_put(glb->mlx, glb->mlx_win, x, y, 0xffff);
                y++;
            }
        }
    }
}

void    draw_x(t_fdf *glb, int p)
{
    int x;
    int x2;
    int y;

    x = glb->map.scaled_tab[p];
    p++;
    y = glb->map.scaled_tab[p];
    p += 2;
    x2 = glb->map.scaled_tab[p];
    while ((x < x2) && (y <= glb->wld.win_y && y >= glb->wld.y_margin_min))
    {
        if (x >= glb->wld.win_x)
            x++;
        else
        {
            mlx_pixel_put(glb->mlx, glb->mlx_win, x, y, 0xffff);
            x++;
        }
    }
}

void    draw_height(t_fdf *glb, int p)
{
    glb->map.co_x = glb->map.scaled_tab[p];
    p++;
    glb->map.co_y = glb->map.scaled_tab[p];
    p++;
    glb->map.z0 = glb->map.scaled_tab[p];
    p++;
    glb->map.y0 = glb->map.scaled_tab[p];
    p++;
    glb->map.y1 = glb->map.scaled_tab[p];
    p++;
    glb->map.z1 = glb->map.scaled_tab[p];
    if (glb->map.z0 < glb->map.z1)
    {
        while (glb->map.z0 < glb->map.z1)
        {
            
        }
    }
    else if (glb->map.z0 > glb->map.z1)
    {
        /* code */
    }
    

}

void    draw_map(t_fdf *glb)
{
    int p;

    p = 0;
    if (glb)
    {
        while (p < ((glb->read.col * glb->read.row) * 3))
        {
            draw_x(glb, p);
            draw_y(glb, p);
            //draw_height(glb, p);
            p += 3;
        }
        mlx_do_sync(glb->mlx);
        return ;
    }
}