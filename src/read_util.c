/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:18:01 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/03 20:19:17 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     skip_over_color(char *line)
{
    int skip;

    skip = 0;
    if (*line == '0')
    {
        line++;
        skip++;
        if (*line == 'x' || *line == 'X')
            while ((ft_isalpha(*line) || ft_isdigit(*line)) && skip++)
                line++;
        else
            return (0);
        return (skip);
    }
    return (skip);
}

int     contains_hex(char *str)
{
    if (*str != '\0')
    {
        if (*str++ == '0')
            if (*str == 'x')
                return (1);
    }
    return (0);
}

int    get_columns(t_fdf *glb, char *line, int inc)
{
    while (*line != '\0' && *line != '\n')
    {
        if (*line >= '0' && *line <= '9')
        {
            glb->read.col += 1;
            while (*line >= '0' && *line <= '9')
                line++;
        }
        if (*line == ',')
            inc = skip_over_color(++line);
        if (inc > 0)
        {
            line += inc;
            inc = 0;
        }
        else if (*line != ' ' && (*line != '\n' && *line != '\0'))
        {
            perror("Bad File...\n");
            return (0);
        }
        if (*line != '\0')
            line++;
    }
    return (glb->read.col);
}

int    get_dimensions(t_fdf *glb)
{
    int     inc;
    char    *ln;

    inc = 0;
    ln = glb->read.line;
    get_next_line(glb->read.fd, &ln);
    if (get_columns(glb, ln, 0))
    {
        glb->read.row += 1;
        free((void *)ln);
        while (get_next_line(glb->read.fd, &ln))
        {
            glb->read.c_pre = glb->read.col;
            glb->read.col = 0;
            get_columns(glb, ln, 0);
            if (glb->read.c_pre != glb->read.col)
                print_error(3, 0);
            glb->read.row += 1;
            free((void *)ln);
        }
    }
    close(glb->read.fd);
    return (1);
}

int    add_points(t_fdf *glb, float *tab, char *line, int i)
{
    int s;

    s = i;
    while ((i - s) < (glb->read.col * 3))
    {
        if (ft_isdigit(*line))
        {
            tab[i++] = (float)glb->map.co_x;
            tab[i++] = (float)glb->map.co_y++;
            tab[i++] = (float)ft_atoi(line);
        }
        while (ft_isdigit(*line))
            line++;
        if (*line == ',' || *line == ' ')
        {
            line++;
            if (contains_hex(line))
                while (*line != '\0' && *line != ' ')
                    line++;
        }
    }
    return (i);
}

int     get_mid(int nbr)
{
    return (nbr / 2);
}

void    set_scaled(t_fdf *glb, int p)
{
    int i;
    int j;
    int changling;
    int r_mid;
    int c_mid;

    changling = 0;
    r_mid = get_mid(glb->read.row);
    i = r_mid * -1;
    c_mid = get_mid(glb->read.col);
    j = c_mid * -1;
    printf("r_mid: %2d\ni: %2d\nc_mid: %d\nj: %d\n\n", r_mid, i, c_mid, j);
    while ((i + r_mid) < glb->read.row)
    {
        while ((j + c_mid) < glb->read.col)
        {
            glb->map.scaled_tab[p] = (i);
            p++;
            glb->map.scaled_tab[p] = j++;
            p++;
            glb->map.scaled_tab[p] = glb->map.tab[p];
            p++;
        }
        j = c_mid * -1;
        i++;
    }
}

void    save_map(t_fdf *glb, char *fn)
{
    int i;

    i = 0;
    glb->map.scaled_tab = (float *)malloc(sizeof(float) * ((glb->read.col * glb->read.row) * 3));
    glb->map.tab = (float *)malloc(sizeof(float) * ((glb->read.col * glb->read.row) * 3));
    glb->read.fd = open(fn, O_RDONLY);
    while (i < (glb->read.col * glb->read.row * 3))
    {
        get_next_line(glb->read.fd, &glb->read.line);
        i = add_points(glb, glb->map.tab, glb->read.line, i);
        glb->map.co_x++;
        glb->map.co_y = 0;
        free((void *)(glb->read.line));
    }
    close(glb->read.fd);
    set_scaled(glb, 0);
}

void    read_map(t_fdf *glb, char *filename)
{
    char *line;

    glb->read.fd = open(filename, O_RDONLY);
    if (glb->read.fd > 2)
    {
        glb->read.line = line;
        if (get_dimensions(glb))
        {
            glb->read.fd = open(filename, O_RDONLY);
            save_map(glb, filename);
        }
        else
            print_error(2, 0);
    }
    else
    {
        print_error(1, glb->read.fd);
    }
}