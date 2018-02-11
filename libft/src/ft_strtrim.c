/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:24:42 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 19:34:08 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		whitespases(char const *s, int f1)
{
	int f;

	f = f1;
	while (s[f])
		f++;
	f--;
	while (s[f] == ' ' || s[f] == '\n' || s[f] == '\t')
		f--;
	if (f > f1)
		return (f - f1);
	return (0);
}

char			*ft_strtrim(char const *s)
{
	char	*re;
	int		f;
	int		y;
	int		i;

	i = 0;
	f = 0;
	if (!s)
		return (0);
	while (s[f] == ' ' || s[f] == '\n' || s[f] == '\t')
		f++;
	y = whitespases(s, f);
	if (!(re = (char *)malloc(sizeof(char) * (y + 2))))
		return (0);
	while (i <= y)
	{
		re[i] = s[f];
		f++;
		i++;
	}
	re[i] = '\0';
	return (re);
}
