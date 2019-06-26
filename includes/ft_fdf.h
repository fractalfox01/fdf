/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:47:55 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/26 10:19:07 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "libft.h"

# define MLX_P      ((*glbl).mlx)
# define MLX_W      ((*glbl).mlx_win)
# define WIN_W      1000
# define WIN_H      1000
# define OFFSET_X   200
# define OFFSET_Y   300

# define DX         ((*fdf).dx)
# define DY         ((*fdf).dy)
# define XINC       ((*fdf).xinc)
# define YINC       ((*fdf).yinc)
# define G_P        ((*fdf).tab) /* GLOBAL POINT REFERENCE */

typedef struct      s_vector
{
    
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
    int             step;
}                   t_points;

typedef struct      s_global
{
    void            *mlx;
    void            *mlx_win;
    t_points        *fdf;
    int             x_scale;
    int             y_scale;
}                   t_global;

void	            ft_fdf(char *str);
void    			console_print_points(t_points fdf);
void                draw_points(t_global *glbl);
void	            add_points(t_points *fdf, char *line, int i);
void        		read_file(t_points *fdf, char *file_name, void *mlx, void *mlx_win);
void                scale_points(t_global *glbl, int i);

#endif
