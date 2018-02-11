/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 17:41:46 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 17:43:23 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t i;
	size_t j;

	if (to_find[0] == '\0')
		return ((char*)str);
	i = 0;
	while (str[i] != '\0')
	{
		i = 0;
		j = 0;
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
