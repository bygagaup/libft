/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 13:55:39 by fschille          #+#    #+#             */
/*   Updated: 2019/01/02 17:47:37 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_del(void *content, size_t content_size)
{
	free((char*)content);
	content = NULL;
	content_size = 0;
}

void	ft_lstaddwheredel(t_list **alst, int i)
{
	t_list	*tmp;
	int		j;

	j = 1;
	tmp = *alst;
	if (i > 0)
	{
		while (j < i && tmp->next)
		{
			tmp = tmp->next;
			j++;
		}
		ft_lstdelone(&tmp, 
		tmp->next = new;
	}
	else
	{
		new->next = tmp;
		*alst = new;
	}
}
