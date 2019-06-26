/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:38:23 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/23 23:26:51 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *cont, size_t c_size)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!(lst))
		return (NULL);
	if (cont == NULL || c_size == 0)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
		return (lst);
	}
	else
	{
		lst->content = malloc(c_size);
		if (!(lst->content))
			return (NULL);
		ft_memcpy((lst->content), cont, c_size);
		lst->content_size = c_size;
		lst->next = NULL;
		return (lst);
	}
	return (NULL);
}
