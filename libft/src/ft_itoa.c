/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 19:19:56 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/27 20:37:23 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_rev(char *str)
{
	char *str_end;
	char c;

	str_end = str + ft_strlen(str) - 1;
	while (str < str_end)
	{
		c = *str;
		*str++ = *str_end;
		*str_end-- = c;
	}
}

static int		size_int(long int n)
{
	int i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n > 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static void		itoa(char *str, int n, int i, int p)
{
	int	m;

	m = 0;
	if (n == -2147483648)
	{
		n++;
		m = 1;
	}
	if (n < 0)
		p = -1;
	n = n * p;
	if (n == 0)
		str[i++] = '0';
	else
		while (n > 0)
		{
			str[i++] = n % 10 + '0';
			n = n / 10;
		}
	if (m == 1)
		str[0] = '8';
	if (p < 0)
		str[i++] = '-';
	str[i] = '\0';
}

char			*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		p;

	str = ft_strnew(size_int(n));
	if (!str)
		return (NULL);
	i = 0;
	p = 1;
	itoa(str, n, i, p);
	ft_rev(str);
	return (str);
}
