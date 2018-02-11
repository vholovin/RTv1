/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:37:23 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 16:00:46 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*b_dest;
	const char	*b_src;

	b_dest = (char*)dest;
	b_src = (char*)src;
	if (b_dest < b_src)
	{
		ft_memcpy(b_dest, b_src, n);
	}
	else
	{
		while (n > 0)
		{
			b_dest[n - 1] = b_src[n - 1];
			n--;
		}
	}
	return (dest);
}
