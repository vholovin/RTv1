/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 20:23:15 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/24 20:24:18 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*res;

	res = (unsigned char *)s;
	while (n > 0)
	{
		*res = (unsigned char)c;
		n--;
		res++;
	}
	return (s);
}
