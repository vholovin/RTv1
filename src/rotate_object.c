/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_object.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 15:09:14 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:24:56 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static t_param	rad_to_grad(t_param angle)
{
	angle.x = 3.14 * angle.x / 180;
	angle.y = 3.14 * angle.y / 180;
	angle.z = 3.14 * angle.z / 180;
	return (angle);
}

t_object		*rotate_object(t_object *object)
{
	t_param	rotate;
	t_param	angle;

	rotate = object->rotate;
	angle = rad_to_grad(object->angle);
	if (object->angle.x != 0.0)
	{
		object->rotate.x = rotate.x * cosf(angle.x) + rotate.z * sinf(angle.x);
		object->rotate.z = rotate.x * (-sinf(angle.x))
			+ rotate.z * cosf(angle.x);
	}
	if (object->angle.y != 0.0)
	{
		object->rotate.y = rotate.y * cosf(angle.y)
			+ rotate.z * (-sinf(angle.y));
		object->rotate.z = rotate.y * sinf(angle.y) + rotate.z * cosf(angle.y);
	}
	if (object->angle.z != 0.0)
	{
		object->rotate.x = rotate.x * cosf(angle.z) + rotate.y * sinf(angle.z);
		object->rotate.y = rotate.x * (-sinf(angle.z))
			+ rotate.y * cosf(angle.z);
	}
	return (object);
}
