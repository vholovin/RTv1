/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:30:00 by exam              #+#    #+#             */
/*   Updated: 2017/04/10 13:48:51 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_hex(char s)
{
	int n;

	n = 0;
	if (s == 'a' || s == 'A')
		n = 10;
	if (s == 'b' || s == 'B')
		n = 11;
	if (s == 'c' || s == 'C')
		n = 12;
	if (s == 'd' || s == 'D')
		n = 13;
	if (s == 'e' || s == 'E')
		n = 14;
	if (s == 'f' || s == 'F')
		n = 15;
	return (n);
}

static int		ft_atoi_(const char *str, int str_base, int i)
{
	int n;

	n = 0;
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9')
				|| (str[i] >= 'a' && str[i] <= 'f')
				|| (str[i] >= 'A' && str[i] <= 'F')))
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = n * str_base + (str[i] - '0');
		if ((str[i] >= 'a' && str[i] <= 'f')
				|| (str[i] >= 'A' && str[i] <= 'F'))
		{
			n = n * str_base + ft_hex(str[i]);
		}
		i++;
	}
	return (n);
}

int				ft_atoi_base(const char *str, int str_base)
{
	int p;
	int i;

	i = 0;
	p = 1;
	while (str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		p = p * -1;
		i++;
	}
	return (ft_atoi_(str, str_base, i) * p);
}
