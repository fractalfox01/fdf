/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_console_log.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:22:31 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/20 16:02:04 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../includes/ft_fdf.h"
#include "../includes/libft.h"
#include "../minilibx/mlx.h"

void    console_print_points(t_points fdf)
{
    int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (fdf.height * fdf.width))
	{
		ft_putstr("point ");
		ft_putchar('a' + j);
		ft_putnbr(i);
		ft_putstr(":\t");
		ft_putnbr(fdf.tab[i][0]);
		ft_putchar(' ');
		ft_putnbr(fdf.tab[i][1]);
		ft_putchar(' ');
		ft_putnbr(fdf.tab[i][2]);
		ft_putchar('\n');
		j = 0;
		i++;
	}
}