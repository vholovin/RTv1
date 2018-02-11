/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:02:31 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 16:35:21 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *b_s;

	b_s = (unsigned char*)s;
	while (n > 0)
	{
		if (*b_s != (unsigned char)c)
			b_s++;
		else
			return (b_s);
		n--;
	}
	return (NULL);
}
