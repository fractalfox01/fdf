/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 19:42:21 by tvandivi          #+#    #+#             */
/*   Updated: 2019/02/24 21:37:29 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ptr;
	t_list	*newlst;
	t_list	*cat;

	if (!lst || !f)
		return (NULL);
	cat = f(lst);
	if (!(ptr = ft_lstnew(cat->content, cat->content_size)))
		return (NULL);
	lst = lst->next;
	newlst = ptr;
	while (lst)
	{
		cat = f(lst);
		if (!(ptr->next = ft_lstnew(cat->content, cat->content_size)))
			return (NULL);
		ptr = ptr->next;
		lst = lst->next;
	}
	return (newlst);
}
