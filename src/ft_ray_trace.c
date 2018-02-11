/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ray_trace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:28:30 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:25:15 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void		set_ray(t_rtv1 *rtv1, size_t i, size_t j)
{
	double	u;
	double	v;

	u = (W - (double)j * 2.0) / H;
	v = (H - (double)i * 2.0) / W;
	if (H > W)
		u *= ((double)H / (double)W);
	else
		v /= ((double)H / (double)W);
	rtv1->ray->z = ft_vector_sub(rtv1->camera->rotate, rtv1->camera->position);
	rtv1->ray->z = ft_vector_norm(rtv1->ray->z);
	rtv1->ray->y = ft_vector_norm(
		ft_vector_cross(rtv1->ray->z, (t_param){0.0, 1.0, 0.0}));
	rtv1->ray->x = ft_vector_cross(rtv1->ray->y, rtv1->ray->z);
	rtv1->ray->direction = ft_vector_norm(
		(t_param){u * rtv1->ray->y.x + v * rtv1->ray->x.x
		+ rtv1->camera->angle * rtv1->ray->z.x, u * rtv1->ray->y.y
		+ v * rtv1->ray->x.y + rtv1->camera->angle * rtv1->ray->z.y,
		u * rtv1->ray->y.z + v * rtv1->ray->x.z + rtv1->camera->angle
		* rtv1->ray->z.z});
	camera_rotate(rtv1, rtv1->camera->rotate_xyz.x,
		rtv1->camera->rotate_xyz.y, rtv1->camera->rotate_xyz.z);
}

void			ft_ray_trace(t_rtv1 *rtv1, size_t i, size_t j)
{
	t_object	*cross_object;
	t_param		color_1;
	t_param		color_2;

	cross_object = NULL;
	color_1 = (t_param){0.0, 0.0, 0.0};
	color_2 = (t_param){0.0, 0.0, 0.0};
	set_ray(rtv1, i, j);
	if ((cross_object = ft_cross_object(rtv1, rtv1->object,
		rtv1->ray->direction, rtv1->camera->position)))
		color_1 = ft_lambert(rtv1, cross_object, rtv1->light);
	color_2.x += ft_clamp(color_1.x, 0.0, 1.0);
	color_2.y += ft_clamp(color_1.y, 0.0, 1.0);
	color_2.z += ft_clamp(color_1.z, 0.0, 1.0);
	rtv1->ray->color.rgb.r = color_2.x * 255;
	rtv1->ray->color.rgb.g = color_2.y * 255;
	rtv1->ray->color.rgb.b = color_2.z * 255;
}
