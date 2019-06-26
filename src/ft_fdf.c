/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:54:15 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/19 00:36:13 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

int		count_columns(char *f_name, int count, int i, t_points *fdf)
{
	int		fd;
	char	*line;
	int		size;

	fd = open(f_name, O_RDONLY);
	get_next_line(fd, &line);
	while (i < (size = ft_strlen(line)))
	{
		if (ft_isdigit(line[i]))
		{
			count++;
			i++;
			while (ft_isdigit(line[i]))
				i++;
		}
		while (i < size && (ft_isdigit(line[i])) == 0)
			i++;
	}
	while (get_next_line(fd, &line))
		fdf->height++;
	ft_strdel(&line);
	close(fd);
	return (count);
}

void	free_points(t_points fdf)
{
	int i;

	i = 0;
	while (i < (fdf.width * fdf.height))
	{
		free((void *)fdf.tab[i]);
		i++;
	}
	free((void *)fdf.tab);
}

int	*key_watch(void)
{
	int	*ptr;

	return (NULL);
}

int		exit_fdf(int key, t_global *glbl)
{
	ft_putstr("Key Event.\n");
	mlx_destroy_window(glbl->mlx, glbl->mlx_win);
	free_points(*glbl->fdf);
	ft_putstr("finished freeing..\n");
	exit(0);
	return (0);
}

void	ft_fdf(char *map)
{
	void		*mlx;
	void		*mlx_win;
	t_global	globe;
	t_points	fdf;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIN_W, WIN_H, "FDF");
	globe.mlx = mlx;
	globe.mlx_win = mlx_win;
	globe.fdf = &fdf;
	fdf.height = 1;
	fdf.width = count_columns(map, 0, 0, &fdf);
	read_file(&fdf, map, mlx, mlx_win);
	scale_points(&globe, 1);
	console_print_points(fdf);
	//draw_points(&globe);
	ft_putstr("done Drawing...\n");
	mlx_key_hook(mlx_win, exit_fdf, &globe);
	mlx_loop(mlx);
}
