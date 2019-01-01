/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fschille <fschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 21:27:26 by fschille          #+#    #+#             */
/*   Updated: 2019/01/01 18:00:45 by fschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_numarr(char const *s, char c)
{
	size_t	i;
	int		res;
	size_t	len;

	i = 0;
	res = 0;
	len = ft_strlen(s);
	while (s[i] && i < len)
	{
		if (s[i] != c && i < len)
		{
			while (s[i + 1] != c && i < len)
			{
				i++;
			}
			i++;
			res = res + 1;
		}
		i++;
	}
	return (res);
}

static char	*ft_writearr(char const *s, char c, int n, char *res)
{
	int		i;
	int		j;
	int		n_arr;

	i = -1;
	j = 0;
	n_arr = 0;
	while (s[++i])
		if (s[i] != c)
		{
			while (s[i + 1] != c && s[i + 1] != '\0')
			{
				if (n_arr == n)
					res[j++] = s[i];
				i++;
			}
			if (n_arr == n)
				res[j++] = s[i];
			i++;
			n_arr = n_arr + 1;
		}
	return (res);
}

static int	ft_memarr(char const *s, char c, int n)
{
	int		i;
	int		n_arr;
	int		res;

	i = 0;
	n_arr = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			while (s[i + 1] != c && s[i + 1] != '\0')
			{
				if (n_arr == n)
					res++;
				i++;
			}
			i++;
			n_arr = n_arr + 1;
		}
		i++;
	}
	return (res);
}

static int	ft_check(char **res, int i)
{
	int	j;

	j = 0;
	if (res[i] == NULL)
	{
		while (j < i)
		{
			ft_strdel(&res[j]);
			j++;
		}
		free(*res);
		res = NULL;
		return (1);
	}
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**res;
	int		numarr;
	int		memarr;

	i = 0;
	if (!s)
		return (NULL);
	numarr = ft_numarr(s, c);
	res = (char**)malloc((numarr + 1) * sizeof(char*));
	if (res == NULL)
		return (NULL);
	while (i < numarr)
	{
		memarr = ft_memarr(s, c, i);
		res[i] = ft_strnew(memarr);
		if (ft_check(res, i) == 1)
			return (NULL);
		res[i] = ft_writearr(s, c, i, res[i]);
		i++;
	}
	res[i] = NULL;
	return (res);
}
