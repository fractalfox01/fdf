/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 13:23:52 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/02 15:14:38 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    free_map(t_fdf *glb)
{
    int i;

    i = 0;
    //system("leaks fdf");
    if (glb)
    {
        free((void *)(glb->map.tab));
        ft_putstr("Done freeing...\n");
    }
}