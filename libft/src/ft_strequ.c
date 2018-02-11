/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 19:18:34 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 19:19:01 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	if ((!s1 && s2) || (!s2 && s1) || (!s1 && !s2))
		return (0);
	while (*s1 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if ((unsigned char)*s1 - (unsigned char)*s2 == 0)
		return (1);
	else
		return (0);
}
