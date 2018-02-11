/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 15:35:43 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 15:36:39 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*b_dest;
	const char	*b_src;

	b_dest = (char*)dest;
	b_src = (char*)src;
	while (n > 0 && *b_src != c)
	{
		*b_dest = *b_src;
		n--;
		b_dest++;
		b_src++;
	}
	if (n > 0)
	{
		*b_dest = *b_src;
		b_dest++;
		b_src++;
		return ((void*)b_dest);
	}
	else
		return (NULL);
}
