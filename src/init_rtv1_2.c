/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rtv1_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 13:19:34 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/12 15:50:55 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_ray	*init_ray(void)
{
	t_ray	*ray;

	if (!(ray = (t_ray*)malloc(sizeof(t_ray))))
		error(0);
	return (ray);
}

t_keys	*init_keys(void)
{
	t_keys	*keys;

	if (!(keys = (t_keys*)malloc(sizeof(t_keys))))
		error(0);
	keys->pos_up_down = 0;
	keys->pos_left_right = 0;
	keys->pos_forward_back = 0;
	return (keys);
}
