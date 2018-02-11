/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:55:01 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/13 14:55:03 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void		zoom(int keycode, t_rtv1 *rtv1)
{
	if (keycode == 24 && rtv1->camera->angle < 3.0)
		rtv1->camera->angle *= 1.01;
	else if (keycode == 27 && rtv1->camera->angle > 1.0)
		rtv1->camera->angle *= 0.99;
}

static void		rotate(int keycode, t_rtv1 *rtv1)
{
	if (keycode == 126)
		rtv1->camera->rotate_xyz.y += 0.1;
	else if (keycode == 125)
		rtv1->camera->rotate_xyz.y -= 0.1;
	if (keycode == 123)
		rtv1->camera->rotate_xyz.x += 0.1;
	else if (keycode == 124)
		rtv1->camera->rotate_xyz.x -= 0.1;
	if (keycode == 47)
		rtv1->camera->rotate_xyz.z += 0.1;
	else if (keycode == 43)
		rtv1->camera->rotate_xyz.z -= 0.1;
}

int				key_press(int keycode, t_rtv1 *rtv1)
{
	zoom(keycode, rtv1);
	rotate(keycode, rtv1);
	if (keycode == 257)
		rtv1->keys->pos_up_down = 1;
	else if (keycode == 256)
		rtv1->keys->pos_up_down = -1;
	if (keycode == 0)
		rtv1->keys->pos_left_right = 1;
	else if (keycode == 2)
		rtv1->keys->pos_left_right = -1;
	if (keycode == 13)
		rtv1->keys->pos_forward_back = 1;
	else if (keycode == 1)
		rtv1->keys->pos_forward_back = -1;
	return (0);
}

int				key_hook(int keycode, t_rtv1 *rtv1)
{
	if (keycode == 53)
	{
		ft_free(rtv1);
		exit(0);
	}
	if (keycode == 257 || keycode == 256)
		rtv1->keys->pos_up_down = 0;
	if (keycode == 0 || keycode == 2)
		rtv1->keys->pos_left_right = 0;
	if (keycode == 13 || keycode == 1)
		rtv1->keys->pos_forward_back = 0;
	return (0);
}
