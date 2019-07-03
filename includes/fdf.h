#ifndef FDF_H
# define FDF_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "../minilibx/mlx.h"
//#include "../minilibx_macos/mlx_int.h"
#include "../src/libft/libft.h"

typedef struct  s_img
{
    char        *data;
    int         size;
    int         endian;
    int         bpp;
}               t_img;

typedef struct  s_read
{
    int         fd;
    char        *line;
    int         c_pre;
    int         col;
    int         row;
}               t_read;

typedef struct  s_user_space
{
    int         x_offset;
    int         y_offset;
    int         s_x;
    int         s_y;
}               t_world;


typedef struct  s_map
{
    int         *tab;
    int         co_x;
    int         co_y;
    int         z0;
    int         y0;
    int         z1;
    int         y1;
    int         zoom;
    int         iso;
    double      x_val;
    double      theta_y;
    double      theta_z;
}               t_map;

typedef struct  s_fdf
{
    void        *mlx;
    void        *mlx_win;
    void        *mlx_img;
    t_img       img;
    t_read      read;
    t_map       map;
    t_world     wld;
}               t_fdf;

typedef void map_movment(t_fdf *glb);

void    print_usage(int i);
int     fdf(t_fdf *glb, char *filename);
void    read_map(t_fdf *glb, char *filename);
void    print_error(int e_nbr, int info);
void    print_map(t_fdf *glb);
void    free_map(t_fdf *glb);
void    draw_map(t_fdf *glb);
void    map_up(t_fdf *glb);
void    map_down(t_fdf *glb);
void    map_left(t_fdf *glb);
void    map_right(t_fdf *glb);
void    fdf_close(t_fdf *glb);
void    map_reset(t_fdf *glb);
void    map_rotate_right(t_fdf *glb);
void    map_rotate_left(t_fdf *glb);

#endif