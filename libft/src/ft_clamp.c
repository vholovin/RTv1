/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:27:16 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:27:17 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_clamp(float value, float min, float max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return (value);
}
