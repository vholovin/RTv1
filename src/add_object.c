/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:23:07 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/13 15:14:00 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void			check_rotate(t_param rotate)
{
	if ((check_limit_number((int)rotate.x, -1, 1) != 0)
		|| (check_limit_number((int)rotate.y, -1, 1) != 0)
		|| (check_limit_number((int)rotate.z, -1, 1) != 0))
		error(6);
}

static t_object		*add_list_object(t_rtv1 *rtv1, t_object *new_object)
{
	t_object	*main;

	main = rtv1->object;
	if (rtv1->object == NULL)
		return (new_object);
	while (rtv1->object->next != NULL)
		rtv1->object = rtv1->object->next;
	rtv1->object->next = new_object;
	return (main);
}

static t_object		*add_list_light(t_rtv1 *rtv1, t_object *new_light)
{
	t_object	*main;

	main = rtv1->light;
	if (rtv1->light == NULL)
		return (new_light);
	while (rtv1->light->next != NULL)
		rtv1->light = rtv1->light->next;
	rtv1->light->next = new_light;
	return (main);
}

void				add_object_figure(t_rtv1 *rtv1, size_t *i, int type)
{
	t_object	*object;

	if (!(object = (t_object *)malloc(sizeof(t_object))))
		error(0);
	if (ft_strcmp(rtv1->file->scene[*i + 1], "\t{") != 0 ||
			ft_strcmp(rtv1->file->scene[*i + 7], "\t}") != 0)
		error(6);
	object->type = type;
	object->position = multi_param("\t\tPOSITION:", object->position,
			rtv1->file->scene[*i + 2], 6);
	object->rotate = multi_param("\t\tAXES:", object->rotate,
			rtv1->file->scene[*i + 3], 6);
	check_rotate(object->rotate);
	object->angle = multi_param("\t\tANGLE:", object->angle,
			rtv1->file->scene[*i + 4], 6);
	object->color = multi_color("\t\tCOLOR:", object->color,
			rtv1->file->scene[*i + 5], 6);
	object->size = single_param("\t\tSIZE:", rtv1->file->scene[*i + 6], 6);
	*i += 8;
	object = rotate_object(object);
	object->next = NULL;
	rtv1->object = add_list_object(rtv1, object);
}

void				add_object_light(t_rtv1 *rtv1, size_t *i)
{
	t_object	*light;

	if (!(light = (t_object *)malloc(sizeof(t_object))))
		error(0);
	if (ft_strcmp(rtv1->file->scene[*i + 1], "\t{") != 0 ||
			ft_strcmp(rtv1->file->scene[*i + 7], "\t}") != 0)
		error(6);
	light->type = 0;
	light->position = multi_param("\t\tPOSITION:", light->position,
			rtv1->file->scene[*i + 2], 6);
	light->rotate = multi_param("\t\tAXES:", light->rotate,
			rtv1->file->scene[*i + 3], 6);
	check_rotate(light->rotate);
	light->angle = multi_param("\t\tANGLE:", light->angle,
			rtv1->file->scene[*i + 4], 6);
	light->color = multi_color("\t\tCOLOR:", light->color,
			rtv1->file->scene[*i + 5], 6);
	light->size = single_param("\t\tSIZE:", rtv1->file->scene[*i + 6], 6);
	*i += 8;
	light = rotate_object(light);
	light->next = NULL;
	rtv1->light = add_list_light(rtv1, light);
}
