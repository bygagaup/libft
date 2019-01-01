/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:58:15 by fschille          #+#    #+#             */
/*   Updated: 2018/12/09 14:47:59 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_del(void *content, size_t content_size)
{
	free((char*)content);
	content = NULL;
	content_size = 0;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*start;
	t_list	*new_list;
	t_list	*temp;

	if (lst == NULL || f == NULL)
		return (NULL);
	new_list = ft_lstnew(lst->content, lst->content_size);
	if (new_list == NULL)
		return (NULL);
	new_list = f(new_list);
	start = new_list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		temp = ft_lstnew(lst->content, lst->content_size);
		if (temp == NULL)
		{
			ft_lstdel(&start, &ft_del);
			return (NULL);
		}
		temp = f(temp);
		new_list->next = temp;
		new_list = new_list->next;
	}
	return (start);
}
