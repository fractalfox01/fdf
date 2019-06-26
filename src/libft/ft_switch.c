/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 17:21:43 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/15 22:21:19 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

#define	SWITCH_MAXARGS 12

// void	ft_switch(char *str, ...)
// {
// 	va_list	ap;
// 	int		i;

// 	i = 0;
// 	va_start(ap, str);
// 	if (*str == '>')
// 	{

// 	}
// 	else if (*str == '<')
// 	{

// 	}
// 	else if (*str == '=')
// 	{

// 	}
// }

void foo(char *fmt, ...)
{
	va_list ap;
	int 	d;
	char	c;
	char	*s;

	va_start(ap, fmt);
	while (*fmt)
		switch(*fmt++) 
		{
			case 's':                       /* string */
					s = va_arg(ap, char *);
					printf("string %s\n", s);
					break;
			case 'd':                       /* int */
					d = va_arg(ap, int);
					printf("int %d\n", d);
					break;
			case 'c':                       /* char */
					/* Note: char is promoted to int. */
					c = va_arg(ap, int);
					printf("char %c\n", c);
					break;
		}
	va_end(ap);
}
