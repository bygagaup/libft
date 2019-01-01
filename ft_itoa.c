/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:34:24 by fschille          #+#    #+#             */
/*   Updated: 2018/12/07 10:03:16 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_mynbr(char *str, int n, int size)
{
	int i;

	i = 0;
	if (n == -2147483648)
	{
		str[i] = '-';
		i++;
		str[i] = '2';
		i++;
		n = 147483648;
	}
	if (n < 0)
	{
		str[i] = '-';
		i++;
		n = -n;
	}
	if (n >= 10)
	{
		ft_mynbr(str, n / 10, size - 1);
		str[size] = (n % 10) + '0';
	}
	else
		str[size] = n + '0';
	return (str);
}

char		*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = ft_intlen(n);
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	ft_mynbr(str, n, size - 1);
	str[size] = '\0';
	return (str);
}
