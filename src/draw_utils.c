/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 16:34:58 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/22 00:11:30 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     ft_sign(int nbr)
{
    if (nbr < 0)
        return (-1);
    return (1);
}

int     get_color(t_fdf *glb, int z1, int z2)
{
    int x;
    int size;

    size = z2 - z1;
    if (size < 0)
        size = ft_abs(size);
    x = (size * 100) / (glb->map.color_max + ft_abs(glb->map.color_min));
    if (x <= 20)
        return (65280);
    if (x > 10 && x <= 40)
        return (5635840);
    if (x > 40 && x <= 60)
        return (16776960);
    if (x > 60 && x <= 80)
        return (16733440);
    else
        return (16711680);
}

void    rotate_points(t_fdf *glb)
{
    int     i;
    int     j;
    float   ang_x;
    float   ang_y;
    int     y;

    i = 0;
    j = 0;
    ang_x = (glb->cam.rotate_x * M_PI) / 180;
    ang_y = (glb->cam.rotate_y * M_PI) / 180;
    while (i < glb->read.row)
    {
        while (j < glb->read.col * 3)
        {
            y = glb->map.scaled_tab[i][j + 1];
            glb->map.scaled_tab[i][j + 1] = (cos(ang_x) * y) - (sin(ang_x) * (glb->map.scaled_tab[i][j + 2]));
            glb->map.scaled_tab[i][j + 2] = (sin(ang_x) * y) + (cos(ang_x) * (glb->map.scaled_tab[i][j + 2]));
            glb->map.scaled_tab[i][j] = (cos(ang_y) * glb->map.scaled_tab[i][j]) - (sin(ang_y) * glb->map.scaled_tab[i][j + 2]);
            j += 3;
        }
        j = 0;
        i++;
    }
}

void    changer(int m, int *sum, int d, int *j)
{
    if (m >= 1)
    {
        *sum = *sum - d;
        *j = *j + 1;
    }
    else if (m < 0)
    {
        *sum = *sum + d;
        *j = *j - 1;
    }
}

void    draw_x(t_fdf *glb, float  p1[3], float p2[3])
{
    int x1;
    int x2;
    int sum;
    int j;
    int m;

    sum = 0;
    x1 = p1[0];
    x2 = p2[0];
    if (x2 < x1)
    {
        glb->map.dx = (x2 - x1);
        j = p1[1];
        while (x2 < x1)
        {
            sum += p2[1] - p1[1];
            m = sum / glb->map.dx;
            changer(m, &sum, glb->map.dx, &j);
            x2 += 1;
            mlx_pixel_put(glb->mlx, glb->mlx_win, x2 + glb->wld.s_x + glb->wld.x_pad, j + glb->wld.s_y + glb->wld.y_pad, BLUE);
        }
    }
    else
    {
        glb->map.dx = (x2 - x1);
        j = p1[1];
        while (x1 < x2)
        {
            sum += p2[1] - p1[1];
            m = sum / glb->map.dx;
            changer(m, &sum, glb->map.dx, &j);
            x1 += 1;
            mlx_pixel_put(glb->mlx, glb->mlx_win, x1 + glb->wld.s_x + glb->wld.x_pad, j + glb->wld.s_y + glb->wld.y_pad, RED);
        }
    }

}

void    draw_y(t_fdf *glb, float p1[3], float p2[3])
{
    int y1;
    int y2;
    int sum;
    int j;
    int m;

    y1 = p1[1];
    y2 = p2[1];
    sum = 0;
    if (y2 < y1)
    {
        glb->map.dy = y2 - y1;
        j = p1[0];
        //ft_putstr("inner y\n");
        while (y2 < y1)
        {
            sum += p2[0] - p1[0];
            m = sum / glb->map.dy;
            changer(m, &sum, glb->map.dy, &j);
            y2 += 1;
            mlx_pixel_put(glb->mlx, glb->mlx_win, j + glb->wld.s_x + glb->wld.x_pad, y2 + glb->wld.s_y + glb->wld.y_pad, GREEN);
        }
    }
    else
    {
        glb->map.dy = y2 - y1;
        j = p1[0];
        //ft_putstr("inner y\n");
        while (y1 < y2)
        {
            sum += p2[0] - p1[0];
            m = sum / glb->map.dy;
            changer(m, &sum, glb->map.dy, &j);
            y1 += 1;
            mlx_pixel_put(glb->mlx, glb->mlx_win, j + glb->wld.s_x + glb->wld.x_pad, y1 + glb->wld.s_y + glb->wld.y_pad, WHITE);
        }
    }

}

void    draw_map(t_fdf *glb)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (glb)
    {
        while (i < glb->read.row)
        {
            while ((j + 5) < (glb->read.col * 3))
            {
                glb->map.p1[0] = glb->map.scaled_tab[i][j];
                glb->map.p1[1] = glb->map.scaled_tab[i][j + 1];
                glb->map.p1[2] = glb->map.scaled_tab[i][j + 2];
                glb->map.p2[0] = glb->map.scaled_tab[i][j + 3];
                glb->map.p2[1] = glb->map.scaled_tab[i][j + 4];
                glb->map.p2[2] = glb->map.scaled_tab[i][j + 5];
                draw_x(glb, glb->map.p1, glb->map.p2);
                j += 3;
            }
            j = 0;
            i++;
        }
        i = 0;
        j = 0;
        while (i  + 1 < glb->read.row)
        {
            while ((j + 2) < glb->read.col * 3)
            {
                glb->map.p1[0] = glb->map.scaled_tab[i][j];
                glb->map.p1[1] = glb->map.scaled_tab[i][j + 1];
                glb->map.p1[2] = glb->map.scaled_tab[i][j + 2];
                glb->map.p2[0] = glb->map.scaled_tab[i + 1][j];
                glb->map.p2[1] = glb->map.scaled_tab[i + 1][j + 1];
                glb->map.p2[2] = glb->map.scaled_tab[i + 1][j + 2];
                draw_y(glb, glb->map.p1, glb->map.p2);
                j += 3;
            }
            j = 0;
            i++;
        }
        mlx_do_sync(glb->mlx);
        return ;
    }
}