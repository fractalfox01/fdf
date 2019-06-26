/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:24:46 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/24 21:55:28 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	add_first(t_points *fdf, char *line, int i)
{
	int	start;

	start = i;
	while ((i - start) < fdf->width)
	{
		fdf->tab[i] = (int *)malloc(sizeof(int) * 3);
		fdf->tab[i][0] = fdf->x;
		fdf->tab[i][1] = fdf->y;
		fdf->tab[i][2] = ft_atoi(line);
		fdf->y += 1;
		i++;
		while (ft_isdigit(*line))
			line++;
		while (ft_isspace(*line))
			line++;
	}
}

void	add_next(t_points *fdf, char *line, int i)
{
	int	start;

	start = i;
	while ((i - start) < fdf->width)
	{
		fdf->tab[i] = (int *)malloc(sizeof(int) * 3);
		fdf->tab[i][0] = fdf->x;
		fdf->tab[i][1] = fdf->y;
		fdf->tab[i][2] = ft_atoi(line);
		fdf->y += 1;
		i++;
		while (ft_isdigit(*line))
			line++;
		while (ft_isspace(*line))
			line++;
	}
}

void	add_points(t_points *fdf, char *line, int i)
{
	add_next(fdf, line, i);
	fdf->y = 0;
    fdf->x += 1;
}

void		read_file(t_points *fdf, char *file_name, void *mlx, void *mlx_win)
{
	int		**tab;
	int		i;
	char	*line;

	i = 0;
	if (file_name)
	{
		line = ft_strnew(BUFF_SIZE);
		fdf->fd = open(file_name, O_RDONLY);
		fdf->x = 0;
		fdf->y = 0;
		fdf->tab = malloc(sizeof(int *) * (fdf->height * fdf->width));
        fdf->total = (fdf->width * fdf->height);
		while (get_next_line(fdf->fd, &line) == 1)
		{
			add_points(fdf, line, i);
			i += fdf->width;
			ft_memdel((void **)&line);
		}
		close(fdf->fd);
	}
}