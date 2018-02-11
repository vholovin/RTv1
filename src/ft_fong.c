/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fong.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 15:34:29 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/12 15:49:50 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static float	intensity(t_rtv1 *rtv1, t_param vector, t_param normal, float d)
{
	float	intensity;
	float	distance;
	t_param	glow;

	intensity = 0.0;
	glow = ft_vector_scale(normal, (2.0 * ft_vector_dot(normal, vector)));
	glow = ft_vector_sub(vector, glow);
	distance = ft_vector_dot(glow, rtv1->ray->direction);
	if (distance > 0.0)
	{
		intensity = pow(distance, 20.0) * 2 * d;
		intensity = ft_clamp(intensity, 0.0, 1.0);
	}
	return (intensity);
}

t_param			ft_fong(t_rtv1 *rtv1, t_param vector, t_param color, float d)
{
	float fong;

	fong = intensity(rtv1, vector, rtv1->ray->normal, d);
	color.x += fong;
	color.y += fong;
	color.z += fong;
	return (color);
}
