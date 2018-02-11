/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:43:30 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 17:44:07 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	if (to_find[0] == '\0')
		return ((char*)str);
	i = 0;
	while (str[i] != '\0' && len >= ft_strlen(to_find))
	{
		i = 0;
		j = 0;
		len--;
		if (str[i] == to_find[j])
			while (str[i] == to_find[j])
			{
				i++;
				j++;
				if (to_find[j] == '\0')
					return ((char*)str);
			}
		str++;
	}
	return (NULL);
}
