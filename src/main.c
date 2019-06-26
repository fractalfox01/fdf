/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 09:46:21 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/19 00:21:43 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_fdf.h"

int	main(int ac, char **av)
{
	printf("FDF - Working...\n\n\n");
	if (ac == 2)
		ft_fdf(av[1]);
	else
		ft_putstr("What are you trying to do?");
	ft_putstr("\n");
	return (0);
}
