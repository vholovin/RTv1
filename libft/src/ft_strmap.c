/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:14:23 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 19:16:05 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*buf;

	if (!s)
		return (NULL);
	buf = ft_strnew(ft_strlen(s));
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		buf[i] = f(s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
