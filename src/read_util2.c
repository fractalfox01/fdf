/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_util2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 00:32:53 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 00:33:32 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	set_scaled(t_fdf *glb)
{
	int	i;
	int	j;
	int	a;
	int	b;

	a = -1 * ((glb->wld.win_x / (glb->read.col - 1)) / 2) * (glb->read.col - 1);
	b = -1 * ((glb->wld.win_y / (glb->read.row - 1)) / 2) * (glb->read.row - 1);
	i = -1;
	j = 0;
	while ((++i) < glb->read.row)
	{
		while ((j) < glb->read.col * 3)
		{
			glb->map.s_tab[i][j] = a;
			a += glb->wld.x_offset;
			glb->map.s_tab[i][j + 1] = b;
			glb->map.s_tab[i][j + 2] = ((glb->wld.y_offset / 4) * \
					glb->map.tab[i][j + 2]);
			j += 3;
		}
		j = 0;
		a = -1 * ((glb->wld.win_x / (glb->read.col - 1)) / 2) * \
			(glb->read.col - 1);
		b += glb->wld.y_offset;
	}
}

void	save_map(t_fdf *glb, char *fn)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = glb->read.col;
	glb->map.s_tab = (float **)malloc(sizeof(float *) * \
			(glb->read.row * 3) + 1);
	glb->map.tab = (float **)malloc(sizeof(float *) * (glb->read.row * 3));
	glb->read.fd = open(fn, O_RDONLY);
	while (i < (glb->read.row))
	{
		get_next_line(glb->read.fd, &glb->read.line);
		glb->map.tab[i] = (float *)malloc(sizeof(float) * (glb->read.col * 3));
		glb->map.s_tab[i] = (float *)malloc(sizeof(float) * \
				(glb->read.col * 3));
		add_points(glb, glb->map.tab, glb->read.line, i);
		glb->map.x1++;
		glb->map.y1 = 0;
		free((void *)(glb->read.line));
		i++;
	}
	close(glb->read.fd);
}

void	read_map(t_fdf *glb, char *filename)
{
	char	*line;

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
