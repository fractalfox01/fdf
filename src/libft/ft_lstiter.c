/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:41:43 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/24 21:36:41 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*nxt;
	t_list	*tmp;

	if (lst)
	{
		tmp = lst->next;
		f(lst);
		while (tmp != NULL)
		{
			nxt = tmp->next;
			f(tmp);
			tmp = nxt;
		}
	}
}
