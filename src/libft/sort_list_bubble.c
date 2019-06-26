/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_bubble.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvandivi <tvandivi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:54:40 by tvandivi          #+#    #+#             */
/*   Updated: 2019/06/14 16:30:50 by tvandivi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char  *sort_help1(char *tmp, t_list *first, t_list *second)
{
    int nd;

    nd = 0;
    tmp = ft_strnew(first->content_size);
    tmp = ft_strcat((char *)tmp, (char *)first->content);
    ft_memset(first->content, 0, first->content_size);
    ft_memdel((void **)&first->content);
    first->content = ft_strnew(second->content_size);
    first->content = ft_memcpy(first->content, second->content, second->content_size);
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

char *sort_help2(char *tmp, t_list *first, t_list *second)
{
    int nd;

    nd = 0;
    tmp = ft_strnew(second->content_size);
    tmp = ft_strcat((char *)tmp, (char *)second->content);
    ft_memset(second->content, 0, second->content_size);
    ft_memdel((void **)&second->content);
    second->content = ft_strnew(first->content_size);
    second->content = ft_memcpy(second->content, first->content, second->content_size);
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

t_list  *handler(t_list *head, int i, int j)
{
    t_list  *first;
    t_list  *second;
    int     len;

    if (head)
    {
        len = ft_get_lst_len(head);
        first = &*head;
        second = first->next;
        while (i++ < len && first)
        {
            while (j++ < (len - 1) && second)
            {
                if (ft_memcmp((char *)first->content, (char *)second->content, first->content_size) == 0)
                    second = second->next;
                else if (ft_memcmp(first->content, second->content, first->content_size) > 0)
                    sort_help1((char *)NULL, first, second);
                else if (ft_memcmp((char *)first->content, (char *)second->content, first->content_size) < 0)
                    sort_help2((char *)NULL, first, second);
            }
            first = first->next;
            j = i;
        }
        head = first;
    }
    return (head);
}

t_list  *sort_list_bubble(t_list *head)
{
    return (handler(head, 0, 0));
}

// int main(void)
// {
//     t_list *head;
//     t_list *ptr;
//     t_list *tmp = ft_lstnew((void *)"Hello", 6);
//     t_list *tmp1 = ft_lstnew((void *)"world1", 7);
//     t_list *tmp2 = ft_lstnew((void *)"Bacon23", 8);
//     t_list *tmp3 = ft_lstnew((void *)"23Bacon", 8);
//     t_list *tmp4 = ft_lstnew((void *)"Zebra", 6);
//     t_list *tmp5 = ft_lstnew((void *)"Thomas VanDivier", 17);
//     head = tmp;
//     tmp->next = tmp1;
//     tmp1->next = tmp2;
//     tmp2->next = tmp3;
//     tmp3->next = tmp4;
//     tmp4->next = tmp5;
//     sort_list_bubble(head);
//     ptr = head;
//     while (head)
//     {
//         ft_putstr((char *)head->content);
//         ft_putstr("\n");
//         head = head->next;
//     }
//     while (ptr)
//     {
//         head = ptr->next;
//         ft_memset(ptr->content, 0, ptr->content_size);
//         ft_memdel(&ptr->content);
//         ptr = ptr->next;
//     }
// }