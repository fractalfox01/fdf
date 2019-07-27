/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 23:31:10 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 23:58:19 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "../minilibx/mlx.h"
# include "../src/libft/libft.h"

# define WHITE 16777215
# define RED 16711680
# define GREEN 65280
# define Q_GRN 16320
# define H_GRN 32640
# define BLUE 255

typedef struct	s_read
{
	int			fd;
	char		*line;
	char		*file_name;
	int			c_pre;
	int			col;
	int			row;
}				t_read;

typedef struct	s_world
{
	int			x_offset;
	int			y_offset;
	int			x_change;
	int			y_change;
	int			x_margin;
	int			x_pad;
	int			y_margin;
	int			y_pad;
	int			s_x;
	int			s_y;
	int			win_x;
	int			win_y;
}				t_world;

typedef struct	s_camera
{
	int			rotate_x;
	int			rotate_y;
	float		scaler[4];
}				t_cam;

typedef struct	s_map
{
	float		**tab;
	float		**s_tab;
	float		p1[3];
	float		p2[3];
	float		color_max;
	float		color_min;
	int			x1;
	int			y1;
	int			dx;
	int			dy;
	double		theta_y;
	double		theta_z;
}				t_map;

typedef struct	s_fdf
{
	void		*mlx;
	void		*mlx_win;
	t_cam		cam;
	t_read		read;
	t_map		map;
	t_world		wld;
}				t_fdf;

void			print_usage(int i);
int				fdf(t_fdf *glb, char *filename);
void			read_map(t_fdf *glb, char *filename);
void			print_error(int e_nbr, int info);
void			print_map(t_fdf *glb);
void			free_map(t_fdf *glb);
void			draw_map(t_fdf *glb);
void			map_up(t_fdf *glb);
void			map_down(t_fdf *glb);
void			map_left(t_fdf *glb);
void			map_right(t_fdf *glb);
void			fdf_close(t_fdf *glb);
void			map_reset(t_fdf *glb);
void			map_rotate_right(t_fdf *glb);
void			map_rotate_left(t_fdf *glb);
void			map_rotate_up(t_fdf *glb);
void			map_rotate_down(t_fdf *glb);
void			map_scale_up(t_fdf *glb);
void			map_scale_down(t_fdf *glb);
void			init_global(t_fdf *glb, char *filename);
void			init_map(t_fdf *glb);
void			init_read(t_fdf *glb);
void			init_world(t_fdf *glb, t_world *wld);
void			set_scaled(t_fdf *glb);
void			init_camera(t_fdf *glb, t_cam *cam);
void			rotate_points(t_fdf *glb);
void			map_rotate_left_down(t_fdf *glb);
void			map_rotate_right_down(t_fdf *glb);
void			map_rotate_left_up(t_fdf *glb);
void			map_rotate_right_up(t_fdf *glb);
void			changer(int m, int *sum, int d, int *j);
void			swap_points(int *a1, int *a2);
int				skip_digit(char *line);
int				add_points(t_fdf *glb, float **tab, char *line, int ln);
int				get_dimensions(t_fdf *glb);

#endif
