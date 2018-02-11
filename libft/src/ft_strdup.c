/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 15:24:54 by vholovin          #+#    #+#             */
/*   Updated: 2017/01/05 16:44:31 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*bufer;

	bufer = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (bufer == NULL)
		return (NULL);
	else
		return (ft_strcpy(bufer, s));
}
