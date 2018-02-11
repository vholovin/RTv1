/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_check_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:28:39 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/13 15:11:38 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static int		set_check_scene(t_rtv1 *rtv1)
{
	size_t i;

	i = 7;
	while (i < (rtv1->file->endl - 1))
	{
		if (ft_strcmp(rtv1->file->scene[i], "\tLIGHT") == 0)
			add_object_light(rtv1, &i);
		else if (ft_strcmp(rtv1->file->scene[i], "\tPLANE") == 0)
			add_object_figure(rtv1, &i, 1);
		else if (ft_strcmp(rtv1->file->scene[i], "\tSPHERE") == 0)
			add_object_figure(rtv1, &i, 2);
		else if (ft_strcmp(rtv1->file->scene[i], "\tCYLINDER") == 0)
			add_object_figure(rtv1, &i, 3);
		else if (ft_strcmp(rtv1->file->scene[i], "\tCONE") == 0)
			add_object_figure(rtv1, &i, 4);
		else
			error(6);
	}
	return (1);
}

static int		set_check_camera(t_rtv1 *rtv1)
{
	if (ft_strcmp(rtv1->file->scene[0], "CAMERA") != 0)
		return (0);
	if (ft_strcmp(rtv1->file->scene[1], "{") != 0 ||
			ft_strcmp(rtv1->file->scene[4], "}") != 0)
		return (0);
	rtv1->camera->position = multi_param("\tPOSITION:", rtv1->camera->position,
			rtv1->file->scene[2], 5);
	rtv1->camera->rotate = multi_param("\tAXES:", rtv1->camera->rotate,
			rtv1->file->scene[3], 5);
	if ((check_limit_number((int)rtv1->camera->rotate.x, -1, 1) != 0)
		|| (check_limit_number((int)rtv1->camera->rotate.y, -1, 1) != 0)
		|| (check_limit_number((int)rtv1->camera->rotate.z, -1, 1) != 0))
		return (0);
	return (1);
}

void			set_scene(t_rtv1 *rtv1)
{
	if (set_check_camera(rtv1) == 0)
		error(5);
	if (ft_strcmp(rtv1->file->scene[5], "SCENE") != 0 ||
			ft_strcmp(rtv1->file->scene[6], "{") != 0 ||
			ft_strcmp(rtv1->file->scene[rtv1->file->endl - 1], "}") != 0)
		error(6);
	if (set_check_scene(rtv1) == 0)
		error(6);
}
