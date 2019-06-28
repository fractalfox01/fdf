/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:01:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/27 18:37:35 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

void	set_base(int arr[3][3])
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (i < 3)
	{
		while (j < 3)
		{
			if (j == i)
				arr[i][j] = 1;
			else
				arr[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

void    dec_y(t_global *glb)
{
    int	arr[3][3];
	int	**tab;

    glb->y_translate -= 10;
    set_base(arr);
    move_vertical(glb, arr);
}

void    inc_y(t_global *glb)
{
    int	arr[3][3];
	int	**tab;

    glb->y_translate += 10;
    set_base(arr);
    move_vertical(glb, arr);
}

/*
**  [x] [s 0 0]   (x * s) + (x * 0) + (x * 0)
**	[y] [0 t 0] = (y * 0) + (y * t) + (y * 0)
**	[z] [0 0 1]   (z * 0) + (z * 0) + (z * 1)
*/

void	move_vertical(t_global *glb, int arr[3][3])
{
	int	**tab;
	int p;
	int j;

	tab = glb->fdf->tab;
	p = 0;
	j = 0;
	ft_putstr("vertical...\n");
	while (p < glb->fdf->total)
	{
		tab[p][0] = (tab[p][0] * glb->y_translate);
		//tab[p][1] = (tab[p][0] * sin(glb->rot_x)) + (tab[p][1] * cos(glb->rot_x)) + (tab[p][2] * arr[1][2]);
		//tab[p][2] = (tab[p][0] * arr[2][0]) + (tab[p][1] * arr[2][1]) + (tab[p][2] * arr[2][2]);
		p++;
	}
}

void	rotate_y(t_global *glb, int arr[3][3])
{
	int	**tab;
	int p;
	int j;

	tab = glb->fdf->tab;
	p = 0;
	j = 0;
	ft_putstr("Rotating...\n");
	while (p < glb->fdf->total)
	{
		tab[p][0] = (tab[p][0] * cos(glb->rot_x)) + (tab[p][1] * -sin(glb->rot_x)) + (tab[p][2] * arr[0][2]);
		tab[p][1] = (tab[p][0] * sin(glb->rot_x)) + (tab[p][1] * cos(glb->rot_x)) + (tab[p][2] * arr[1][2]);
		tab[p][2] = (tab[p][0] * arr[2][0]) + (tab[p][1] * arr[2][1]) + (tab[p][2] * arr[2][2]);
		tab[p][0] = (tab[p][0] * cos(glb->rot_y)) + (tab[p][1] * -sin(glb->rot_y)) + (tab[p][2] * arr[0][2]);
		tab[p][1] = (tab[p][0] * sin(glb->rot_y)) + (tab[p][1] * cos(glb->rot_y)) + (tab[p][2] * arr[1][2]);
		tab[p][2] = (tab[p][0] * arr[2][0]) + (tab[p][1] * arr[2][1]) + (tab[p][2] * arr[2][2]);
		p++;
	}
}
