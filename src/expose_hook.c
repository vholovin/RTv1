/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:24:22 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/12 14:42:16 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void	mlx_put_pixel_to_image(size_t y, size_t x, int color, t_mlx *mlx)
{
	unsigned int	new_color;
	size_t			i;

	new_color = mlx_get_color_value(mlx->mlx_ptr, color);
	i = x * 4 + y * mlx->size_line;
	mlx->ptr[i] = (new_color & 0xFF);
	mlx->ptr[i + 1] = (new_color & 0xFF00) >> 8;
	mlx->ptr[i + 2] = (new_color & 0xFF0000) >> 16;
}

int			expose_hook(t_rtv1 *rtv1)
{
	size_t	i;
	size_t	j;

	camera_position(rtv1, 5);
	i = 0;
	while (i < H)
	{
		j = 0;
		while (j < W)
		{
			ft_ray_trace(rtv1, i, j);
			mlx_put_pixel_to_image(i, j, rtv1->ray->color.value, rtv1->mlx);
			++j;
		}
		++i;
	}
	mlx_put_image_to_window(rtv1->mlx->mlx_ptr, rtv1->mlx->win_ptr,
		rtv1->mlx->img_ptr, 0, 0);
	return (0);
}
