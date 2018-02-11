/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross_shadow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 14:48:59 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:01:07 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static t_param	set_ray(t_rtv1 *rtv1, t_object *cross_light, t_param position)
{
	t_param ray;

	ray = ft_vector_sub(cross_light->position, position);
	rtv1->ray->distance = sqrtf(ft_vector_dot(ray, ray));
	ray = ft_vector_norm(ray);
	return (ray);
}

int				cross_shadow(t_rtv1 *rtv1, t_object *cross_object,
		t_object *cross_light, t_param position)
{
	t_object	*shadow;
	t_param		ray;
	float		distance;

	shadow = rtv1->object;
	ray = set_ray(rtv1, cross_light, position);
	while (shadow != NULL)
	{
		if (shadow != cross_object)
		{
			if (shadow->type == 1)
				distance = cross_plane(rtv1, shadow, ray, position);
			else if (shadow->type == 2)
				distance = cross_sphere(rtv1, shadow, ray, position);
			else if (shadow->type == 3)
				distance = cross_cylinder(rtv1, shadow, ray, position);
			else if (shadow->type == 4)
				distance = cross_cone(rtv1, shadow, ray, position);
			if (distance > 0.001 && distance < rtv1->ray->distance)
				return (1);
		}
		shadow = shadow->next;
	}
	return (0);
}
