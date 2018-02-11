/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/26 16:05:51 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/26 19:24:18 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(s = (char*)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	while (s1[i] != '\0')
		s[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		s[j++] = s2[i++];
	s[j] = '\0';
	return (s);
}
