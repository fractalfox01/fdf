/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_n_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 13:36:45 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 00:52:46 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

/*
** Reads size number of characters from the file pointed to by fd.
*/

int		get_n_char(int fd, char **line, int size)
{
	static char	*tab[FDLIMIT];
	char		*buf;
	int			a;

	if (fd < 0 || !(line) || size <= 0)
		return (-1);
	if (!(tab[fd]))
		tab[fd] = ft_strdup("");
	buf = ft_strnew(size + 1);
	if ((a = read(fd, buf, size)) > 0)
	{
		*line = ft_strdup(buf);
		free(buf);
		free(tab[fd]);
		return (1);
	}
	return (-1);
}
