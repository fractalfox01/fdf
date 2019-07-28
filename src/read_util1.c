/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_util1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:18:01 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/28 09:30:50 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		skip_over_color(char *line)
{
	int	skip;

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

int		contains_hex(char *str)
{
	if (*str != '\0')
	{
		if (*str++ == '0')
			if (*str == 'x')
				return (1);
	}
	return (0);
}

int		get_columns(t_fdf *glb, char *line, int inc)
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

int		get_dimensions(t_fdf *glb, int inc)
{
	char	*ln;

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
			if (get_columns(glb, ln, 0))
			{
				if (glb->read.c_pre != glb->read.col)
					print_error(3, 0);
				glb->read.row += 1;
				free((void *)ln);
			}
			else
				return (0);
		}
	}
	close(glb->read.fd);
	return (1);
}

int		add_points(t_fdf *glb, float **tab, char *line, int ln)
{
	int	i;

	i = 0;
	while (i < (glb->read.col * 3))
	{
		if (ft_isdigit(*line))
		{
			tab[ln][i++] = (float)glb->map.x1;
			tab[ln][i++] = (float)glb->map.y1++;
			tab[ln][i] = (float)ft_atoi(line);
			if (tab[ln][i] > glb->map.color_max)
				glb->map.color_max = tab[ln][i];
			if (tab[ln][i] < glb->map.color_min)
				glb->map.color_min = tab[ln][i];
			i++;
		}
		line += skip_digit(line);
		if (*line == ',' || *line == ' ')
		{
			line++;
			if (contains_hex(line))
				line = ft_strchr(line, ' ');
		}
	}
	return (i);
}
