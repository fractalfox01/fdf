/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_bubble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:54:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/07/26 00:44:10 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*sort_help1(char *tmp, t_list *first, t_list *second)
{
	int	nd;

	nd = 0;
	tmp = ft_strnew(first->content_size);
	tmp = ft_strcat((char *)tmp, (char *)first->content);
	ft_memset(first->content, 0, first->content_size);
	ft_memdel((void **)&first->content);
	first->content = ft_strnew(second->content_size);
	first->content = ft_memcpy(first->content, second->content, \
		second->content_size);
	ft_memset(second->content, 0, second->content_size);
	ft_memdel((void **)&second->content);
	second->content = ft_strnew(first->content_size);
	second->content = ft_memcpy(second->content, tmp, first->content_size);
	nd = first->content_size;
	first->content_size = second->content_size;
	second->content_size = nd;
	second = second->next;
	return (tmp);
}

char	*sort_help2(char *tmp, t_list *first, t_list *second)
{
	int	nd;

	nd = 0;
	tmp = ft_strnew(second->content_size);
	tmp = ft_strcat((char *)tmp, (char *)second->content);
	ft_memset(second->content, 0, second->content_size);
	ft_memdel((void **)&second->content);
	second->content = ft_strnew(first->content_size);
	second->content = ft_memcpy(second->content, first->content, \
		second->content_size);
	ft_memset(first->content, 0, first->content_size);
	ft_memdel((void **)&first->content);
	first->content = ft_strnew(second->content_size);
	first->content = ft_memcpy(first->content, tmp, second->content_size);
	nd = second->content_size;
	second->content_size = first->content_size;
	first->content_size = nd;
	second = second->next;
	return (tmp);
}

t_list	*handler(t_list *head, int i, int j)
{
	t_list	*f;
	t_list	*s;
	int		len;

	len = ft_get_lst_len(head);
	f = &*head;
	s = f->next;
	while (i++ < len && f)
	{
		while (j++ < (len - 1) && s)
		{
			if (ft_memcmp((char *)f->content, (char *)s->content, \
					f->content_size) == 0)
				s = s->next;
			else if (ft_memcmp(f->content, s->content, f->content_size) > 0)
				sort_help1((char *)NULL, f, s);
			else if (ft_memcmp((char *)f->content, (char *)s->content, \
					f->content_size) < 0)
				sort_help2((char *)NULL, f, s);
		}
		f = f->next;
		j = i;
	}
	head = f;
	return (head);
}

t_list	*sort_list_bubble(t_list *head)
{
	return (handler(head, 0, 0));
}
