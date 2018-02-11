/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:35:14 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/28 14:25:09 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char		*b_dst;
	const char	*b_src;

	b_dst = (char *)dst;
	b_src = (char *)src;
	while (n > 0)
	{
		*b_dst = *b_src;
		n--;
		b_dst++;
		b_src++;
	}
	return ((void *)dst);
}
