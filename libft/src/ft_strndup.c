/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:22:05 by vholovin          #+#    #+#             */
/*   Updated: 2017/01/30 16:22:08 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *dst;

	if (!(dst = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	dst = ft_strncpy(dst, s1, n);
	dst[n] = '\0';
	return (dst);
}
