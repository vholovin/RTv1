/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:56:53 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:01:20 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

t_param		ft_vector_sub(t_param v_1, t_param v_2)
{
	t_param	sub;

	sub.x = v_1.x - v_2.x;
	sub.y = v_1.y - v_2.y;
	sub.z = v_1.z - v_2.z;
	return (sub);
}

t_param		ft_vector_norm(t_param v)
{
	double	n;

	n = 1.0 / sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	v.x *= n;
	v.y *= n;
	v.z *= n;
	return (v);
}

t_param		ft_vector_cross(t_param v_1, t_param v_2)
{
	t_param	v;

	v.x = v_1.y * v_2.z - v_1.z * v_2.y;
	v.y = v_1.z * v_2.x - v_1.x * v_2.z;
	v.z = v_1.x * v_2.y - v_1.y * v_2.x;
	return (v);
}

float		ft_vector_dot(t_param v_1, t_param v_2)
{
	float	res;

	res = v_1.x * v_2.x + v_1.y * v_2.y + v_1.z * v_2.z;
	return (res);
}

t_param		ft_vector_scale(t_param v, float n)
{
	t_param	res;

	res.x = v.x * n;
	res.y = v.y * n;
	res.z = v.z * n;
	return (res);
}
