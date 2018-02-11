/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:55:37 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:18:37 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void	camera_position_0x_0y(t_rtv1 *rtv1, float step_x, float step_y)
{
	if (rtv1->keys->pos_left_right)
	{
		rtv1->camera->rotate = (t_param){
			rtv1->camera->rotate.x + step_x * rtv1->ray->y.x,
			rtv1->camera->rotate.y + step_x * rtv1->ray->y.y,
			rtv1->camera->rotate.z + step_x * rtv1->ray->y.z};
		rtv1->camera->position = (t_param){
			rtv1->camera->position.x + step_x * rtv1->ray->y.x,
			rtv1->camera->position.y + step_x * rtv1->ray->y.y,
			rtv1->camera->position.z + step_x * rtv1->ray->y.z};
	}
	if (rtv1->keys->pos_up_down)
	{
		rtv1->camera->rotate = (t_param){
			rtv1->camera->rotate.x + step_y * rtv1->ray->x.x,
			rtv1->camera->rotate.y + step_y * rtv1->ray->x.y,
			rtv1->camera->rotate.z + step_y * rtv1->ray->x.z};
		rtv1->camera->position = (t_param){
			rtv1->camera->position.x + step_y * rtv1->ray->x.x,
			rtv1->camera->position.y + step_y * rtv1->ray->x.y,
			rtv1->camera->position.z + step_y * rtv1->ray->x.z};
	}
}

void		camera_position(t_rtv1 *rtv1, float step)
{
	float	step_x;
	float	step_y;
	float	step_z;

	step_x = step * rtv1->keys->pos_left_right;
	step_y = step * rtv1->keys->pos_up_down;
	step_z = step * rtv1->keys->pos_forward_back;
	camera_position_0x_0y(rtv1, step_x, step_y);
	if (rtv1->keys->pos_forward_back)
	{
		rtv1->camera->rotate = (t_param){
			rtv1->camera->rotate.x + step_z * rtv1->ray->z.x,
			rtv1->camera->rotate.y + step_z * rtv1->ray->z.y,
			rtv1->camera->rotate.z + step_z * rtv1->ray->z.z};
		rtv1->camera->position = (t_param){
			rtv1->camera->position.x + step_z * rtv1->ray->z.x,
			rtv1->camera->position.y + step_z * rtv1->ray->z.y,
			rtv1->camera->position.z + step_z * rtv1->ray->z.z};
	}
}

void		camera_rotate(t_rtv1 *rtv1, float angle_x, float angle_y,
				float angle_z)
{
	t_param		direction;

	(void)angle_x;
	direction = rtv1->ray->direction;
	rtv1->ray->direction.y = direction.y * cosf(angle_y)
			+ direction.z * sinf(angle_y);
	rtv1->ray->direction.z = direction.y * (-sinf(angle_y))
			+ direction.z * cosf(angle_y);
	direction = rtv1->ray->direction;
	rtv1->ray->direction.x = direction.x * cosf(angle_x)
			+ direction.z * (-sinf(angle_x));
	rtv1->ray->direction.z = direction.x * sinf(angle_x)
			+ direction.z * cosf(angle_x);
	direction = rtv1->ray->direction;
	rtv1->ray->direction.x = direction.x * cosf(angle_z)
			+ direction.y * sinf(angle_z);
	rtv1->ray->direction.y = direction.x * (-sinf(angle_z))
			+ direction.y * cosf(angle_z);
}
