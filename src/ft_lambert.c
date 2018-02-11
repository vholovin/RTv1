/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lambert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:37:11 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:01:10 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static t_param	intensity(t_object *object, t_object *light,
			t_param color, float lambert)
{
	color.x += (lambert * ((float)object->color.rgb.r / 255.0)
		* ((float)light->color.rgb.r / 255.0));
	color.y += (lambert * ((float)object->color.rgb.g / 255.0)
		* ((float)light->color.rgb.g / 255.0));
	color.z += (lambert * ((float)object->color.rgb.b / 255.0)
		* ((float)light->color.rgb.b / 255.0));
	return (color);
}

static t_param	ft_normal(t_rtv1 *rtv1, t_object *cross_object,
			t_param position)
{
	t_param		normal;
	t_param		temp_1;
	t_param		temp_2;

	if (cross_object->type == 1)
		normal = cross_object->rotate;
	if (cross_object->type == 2)
		normal = ft_vector_sub(position, cross_object->position);
	if (cross_object->type == 3 || cross_object->type == 4)
	{
		temp_1 = ft_vector_scale(cross_object->rotate,
			(ft_vector_dot(rtv1->ray->direction, cross_object->rotate)
				* rtv1->ray->distance
				+ ft_vector_dot(rtv1->ray->vector, cross_object->rotate)));
		if (cross_object->type == 4)
			temp_1 = ft_vector_scale(temp_1, (1
				+ pow(tan(cross_object->size), 2)));
		temp_2 = ft_vector_sub(position, cross_object->position);
		normal = ft_vector_sub(temp_2, temp_1);
	}
	normal = ft_vector_norm(normal);
	return (normal);
}

static t_param	set_position(t_camera *camera, t_ray *ray)
{
	t_param	position;

	position.x = camera->position.x + ray->distance * ray->direction.x;
	position.y = camera->position.y + ray->distance * ray->direction.y;
	position.z = camera->position.z + ray->distance * ray->direction.z;
	return (position);
}

t_param			ft_lambert(t_rtv1 *rtv1, t_object *cross_object,
			t_object *cross_light)
{
	t_param		color;
	t_param		position;
	t_param		vector;
	float		d;
	float		lambert;

	color = (t_param){0.0, 0.0, 0.0};
	position = set_position(rtv1->camera, rtv1->ray);
	rtv1->ray->normal = ft_normal(rtv1, cross_object, position);
	while (cross_light != NULL)
	{
		lambert = 0.0;
		vector = ft_vector_sub(cross_light->position, position);
		d = ft_clamp((1.0 / sqrtf(sqrtf(ft_vector_dot(vector,
			vector)))), 0.0, 1.0);
		vector = ft_vector_norm(vector);
		if (cross_shadow(rtv1, cross_object, cross_light, position) == 0)
			lambert += ft_clamp(ft_vector_dot(vector,
						rtv1->ray->normal), 0.0, 1.0);
		lambert = ft_clamp(lambert * 4.0 * d, 0.0, 1.0);
		color = intensity(cross_object, cross_light, color, lambert);
		color = ft_fong(rtv1, vector, color, d);
		cross_light = cross_light->next;
	}
	return (color);
}
