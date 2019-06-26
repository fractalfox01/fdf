/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:40:02 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/24 17:12:50 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nxt;
	t_list	*tmp;

	if (alst)
	{
		tmp = (*alst)->next;
		del(*alst, sizeof(*alst));
		while (tmp != NULL)
		{
			nxt = tmp->next;
			del(tmp->content, tmp->content_size);
			free(tmp);
			tmp = nxt;
		}
		*alst = NULL;
		free(*alst);
	}
}
