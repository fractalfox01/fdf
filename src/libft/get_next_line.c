/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 13:21:39 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 00:49:37 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int		null_check(char **line, char **tab)
{
	if (ft_strlen(*tab) > 0)
	{
		ft_memdel((void **)line);
		free(*line);
		*line = ft_strjoin(*tab, "");
		ft_bzero(*tab, ft_strlen(*tab));
		return (1);
	}
	return (0);
}

int		read_next_buffer(int a, char **tab, char **line, char *buf)
{
	int	j;

	j = 0;
	buf[a] = '\0';
	while (buf[j] != '\n' && j < (a - 1))
		j++;
	if (buf[j] == '\n')
	{
		buf[j] = '\0';
		ft_memdel((void **)line);
		*line = ft_strjoin(*tab, buf);
		ft_bzero(*tab, ft_strlen(*tab));
		free(*tab);
		if (j >= (a - 1))
			*tab = ft_strdup("");
		else
			*tab = ft_strdup(buf + (j + 1));
		free(buf);
		return (1);
	}
	return (0);
}

int		chomp_line(char **tab, char **line)
{
	char	*tmp;
	char	*ptr;

	if (!((ft_strchr(*tab, '\n')) == NULL))
	{
		ft_memdel((void **)line);
		tmp = ft_strchr(*tab, '\n');
		*tmp = '\0';
		free(*line);
		*line = ft_strdup(*tab);
		tmp++;
		ft_bzero(*tab, ft_strlen(*tab));
		ptr = ft_strdup(*tab);
		*tab = ft_strjoin(ptr, tmp);
		free(ptr);
		return (1);
	}
	return (0);
}

void	set_and_free(char **tab, char **buf)
{
	char *ptr;

	ptr = ft_strdup(*tab);
	free(*tab);
	*tab = ft_strjoin(ptr, *buf);
	free(ptr);
	ft_memset(*buf, '\0', BUFFSIZE);
	free(*buf);
	*buf = ft_strnew(BUFFSIZE + 1);
}

int		get_next_line(int fd, char **line)
{
	static char	*tab[FDLIMIT];
	char		*buf;
	int			a;

	if (fd < 0 || !(line) || BUFFSIZE <= 0)
		return (-1);
	if (!(tab[fd]))
		tab[fd] = ft_strdup("");
	buf = ft_strnew(BUFFSIZE + 1);
	if (ft_strlen(tab[fd]) > 0)
		if (chomp_line(&tab[fd], line) == 1)
			return (1);
	while ((a = read(fd, buf, BUFFSIZE)) >= 0)
	{
		if (a == 0)
		{
			free(buf);
			return (null_check(line, &tab[fd]));
		}
		if ((read_next_buffer(a, &tab[fd], line, buf)) == 1)
			return (1);
		set_and_free(&tab[fd], &buf);
	}
	return (-1);
}
