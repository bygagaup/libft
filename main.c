/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 14:14:30 by fschille          #+#    #+#             */
/*   Updated: 2019/01/02 17:46:28 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_ftlst(t_list *elem)
{
	elem->content_size = 1000;
	return (elem);
}

int main()
{
	t_list *lismap = NULL;
	t_list *lis = NULL;
	t_list *lis1 = NULL;
	t_list *lis2 = NULL;
	t_list *lis3 = NULL;
	t_list *lis4 = NULL;
	t_list *lis5 = NULL;
//	t_list *lis6 = NULL;

	lis1 = ft_lstnew("qwer0", 6);
	lis2 = ft_lstnew("qwer1", 6);
	lis3 = ft_lstnew("qwer2", 6);
	lis4 = ft_lstnew("qwer3", 6);
	lis5 = ft_lstnew("qwer4", 6);
//	lis6 = ft_lstnew("qwer*", 6);
	ft_lstaddend(&lis, lis1);
	ft_lstaddend(&lis, lis2);
	ft_lstaddend(&lis, lis3);
	ft_lstaddend(&lis, lis4);
	ft_lstaddend(&lis, lis5);
//	ft_lstaddwhere(&lis, lis6, 999);
	lismap = ft_lstmap(lis, &ft_ftlst);
	while (lis)
	{
		printf("%s - %zu\n", lis->content, lis->content_size);
		lis = lis->next;
	}
	while (lismap)
	{
		printf("%s - %zu\n", lismap->content, lismap->content_size);
		lismap = lismap->next;
	}
	return (0);
}
