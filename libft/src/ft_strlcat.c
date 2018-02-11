/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:24:41 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/28 13:49:57 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t end;

	i = 0;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dest[i] && i < size)
		i++;
	while (src[j])
		j++;
	end = i;
	while (src[i - end] && i < size - 1)
	{
		dest[i] = src[i - end];
		i++;
	}
	if (end < size)
		dest[i] = '\0';
	return (end + j);
}
