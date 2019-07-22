/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 14:02:12 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/21 08:13:08 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    print_usage(int i)
{
    if (i == 1)
    {
        ft_putstr(FT_CLEAR_SCREEN);
        ft_putstr(FT_LIGHTCYAN);
        ft_putstr("Welcome to FDF...\n");
        ft_putstr("\nTo use, simply enter the path of a map file (ie. .fdf)\n");
        ft_putstr(FT_GREEN);
        ft_putstr("Example:\n\t./fdf maps/42.fdf\n");
        ft_putstr(FT_END_ATTR);
    }
    else
    {
        ft_putstr(FT_LIGHTCYAN);
        ft_putstr("Welcome to FDF...\n");
        ft_putstr("\nTo use, simply enter the path of a map file (ie. .fdf)\n");
        ft_putstr(FT_GREEN);
        ft_putstr("Example:\n\t./fdf maps/42.fdf\n");
        ft_putstr(FT_END_ATTR);
    }
    
}

void    print_map(t_fdf *glb)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < glb->read.row)
    {
        while (j < (glb->read.col * 3))
        {
            ft_putnbr(glb->map.scaled_tab[i][j]);
            ft_putstr(" ");
            j++;
            if ((j % 3) == 0)
                ft_putchar('\t');
        }
        j = 0;
        i++;
        ft_putchar('\n');
    }
}

void    print_error(int e_nbr, int info)
{
    if (e_nbr == 1)
    {
        perror("Bad file descriptor...\n");
        ft_putstr(ft_strjoin("\tFD received: ", ft_itoa(info)));
        ft_putchar('\n');
    }
    else if (e_nbr == 2)
        perror("Bad input file...\n");
    else if (e_nbr == 3)
    {
        ft_putstr(FT_RED);
        perror("Irregular columns detected.\nIs this intentional?\n");
        ft_putstr(FT_END_ATTR);
    }
    else if (e_nbr == 4)
    {
        ft_putstr(FT_RED);
        perror("Bad input in column being read\n");
        ft_putstr(FT_END_ATTR);
    }
    else
        perror("Unknown error occured...\n");
    if (info != 0)
        print_usage(0);
}