/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 10:04:52 by fschille          #+#    #+#             */
/*   Updated: 2018/12/07 10:24:15 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	c;

	i = ft_strlen(str) - 1;
	j = 0;
	while (i > j)
	{
		c = str[j];
		str[j] = str[i];
		str[i] = c;
		j++;
		i--;
	}
	return (str);
}
