/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cross_object.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:31:48 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:01:15 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

float		cross_plane(t_rtv1 *rtv1, t_object *object, t_param ray,
		t_param position)
{
	float	distance;

	(void)rtv1;
	distance = ((ft_vector_dot(object->rotate, object->position)
		- ft_vector_dot(object->rotate, position))
		/ ft_vector_dot(object->rotate, ray));
	if (distance < 0.0001)
		return (-1);
	return (distance);
}

float		cross_cone(t_rtv1 *rtv1, t_object *object, t_param ray,
		t_param position)
{
	float	a;
	float	b;
	float	c;
	float	d;

	rtv1->ray->vector = ft_vector_sub(position, object->position);
	object->rotate = ft_vector_norm(object->rotate);
	a = ft_vector_dot(ray, ray) - (1 + pow(tan(object->size), 2))
	* pow(ft_vector_dot(ray, object->rotate), 2);
	b = 2 * (ft_vector_dot(ray, rtv1->ray->vector)
	- (1 + pow(tan(object->size), 2)) * ft_vector_dot(ray, object->rotate)
	* ft_vector_dot(rtv1->ray->vector, object->rotate));
	c = ft_vector_dot(rtv1->ray->vector, rtv1->ray->vector)
	- (1 + pow(tan(object->size), 2))
	* pow(ft_vector_dot(rtv1->ray->vector, object->rotate), 2);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	if (rtv1->ray->distance > ((-b - sqrtf(d)) / (2 * a)))
		return ((-b - sqrtf(d)) / (2 * a));
	else
		return ((-b + sqrtf(d)) / (2 * a));
}

float		cross_cylinder(t_rtv1 *rtv1, t_object *object, t_param ray,
		t_param position)
{
	float	a;
	float	b;
	float	c;
	float	d;

	rtv1->ray->vector = ft_vector_sub(position, object->position);
	object->rotate = ft_vector_norm(object->rotate);
	a = ft_vector_dot(ray, ray)
		- pow(ft_vector_dot(ray, object->rotate), 2);
	b = 2 * (ft_vector_dot(ray, rtv1->ray->vector)
	- (ft_vector_dot(ray, object->rotate)
	* ft_vector_dot(rtv1->ray->vector, object->rotate)));
	c = ft_vector_dot(rtv1->ray->vector, rtv1->ray->vector)
	- pow(ft_vector_dot(rtv1->ray->vector, object->rotate), 2)
	- pow(object->size, 2);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	if (((-b + sqrtf(d)) / (2 * a)) > ((-b - sqrtf(d)) / (2 * a)))
		return ((-b - sqrtf(d)) / (2 * a));
	else
		return ((-b + sqrtf(d)) / (2 * a));
}

float		cross_sphere(t_rtv1 *rtv1, t_object *object, t_param ray,
		t_param position)
{
	float	a;
	float	b;
	float	c;
	float	d;
	t_param	vector;

	(void)rtv1;
	vector = ft_vector_sub(position, object->position);
	a = ft_vector_dot(ray, ray);
	b = 2 * ft_vector_dot(ray, vector);
	c = ft_vector_dot(vector, vector)
			- (object->size * object->size);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (-1);
	if (((-b + sqrtf(d)) / (2 * a)) > ((-b - sqrtf(d)) / (2 * a)))
		return ((-b - sqrtf(d)) / (2 * a));
	else
		return ((-b + sqrtf(d)) / (2 * a));
}

t_object	*ft_cross_object(t_rtv1 *rtv1, t_object *object, t_param ray,
		t_param position)
{
	t_object	*cross_object;
	float		distance;

	cross_object = NULL;
	rtv1->ray->distance = MAX_DISTANCE;
	while (object != NULL)
	{
		if (object->type == 1)
			distance = cross_plane(rtv1, object, ray, position);
		else if (object->type == 2)
			distance = cross_sphere(rtv1, object, ray, position);
		else if (object->type == 3)
			distance = cross_cylinder(rtv1, object, ray, position);
		else if (object->type == 4)
			distance = cross_cone(rtv1, object, ray, position);
		if (distance > 0.0001 && distance < rtv1->ray->distance)
		{
			cross_object = object;
			rtv1->ray->distance = distance;
		}
		object = object->next;
	}
	return (cross_object);
}
