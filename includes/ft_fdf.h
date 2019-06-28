/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:47:55 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/27 18:34:50 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "libft.h"

# define MLX_P      ((*glb).mlx)
# define MLX_W      ((*glb).mlx_win)
# define WIN_W      1700
# define WIN_H      1300
# define WORLD_W    1000
# define WORLD_H    1000

# define DX         ((*fdf).dx)
# define DY         ((*fdf).dy)
# define XINC       ((*fdf).xinc)
# define YINC       ((*fdf).yinc)
# define G_P        ((*fdf).tab) /* GLOBAL POINT REFERENCE */

typedef struct      s_vector
{
    int             x;
    int             y;
    int             err;
    int             e2;
    int             p_start;
}                   t_vec;


typedef struct      s_points
{
    int             **tab;
    int             total;
    int             fd;
    int             dx;
    int             dy;
    int             x;
    int             y;
    int             width;
    int             height;
    int             xinc;
    int             yinc;
    int             xstep;
    int             ystep;
}                   t_points;

typedef struct      s_global
{
    void            *mlx;
    void            *mlx_win;
    t_points        *fdf;
    t_vec           *vec;
    int             **orig;
    int             x_scale;
    int             y_scale;
    int             offset_x;
    int             offset_y;
    float           x_translate;
    float           y_translate;
    double          rot_y;
    double          rot_x;
}                   t_global;

void	            ft_fdf(char *str);
void    			console_print_points(t_points fdf);
void                draw_points(t_global *glbl);
void	            add_points(t_points *fdf, char *line, int i);
int        		    read_file(t_points *fdf, char *file_name, void *mlx, void *mlx_win);
void                scale_points(t_global *glbl, int i);
void	            rotate_y(t_global *glb, int arr[3][3]);
void                inc_y(t_global *glb);
void                dec_y(t_global *glb);
void	            move_vertical(t_global *glb, int arr[3][3]);

#endif
