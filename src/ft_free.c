/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:25:13 by vholovin          #+#    #+#             */
/*   Updated: 2017/09/22 19:25:22 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void			free_split(char **line_split)
{
	size_t	i;

	i = 0;
	while (line_split[i] != '\0')
	{
		free(line_split[i]);
		++i;
	}
	free(line_split);
}

static void		ft_free_mlx(t_rtv1 *rtv1)
{
	mlx_destroy_image(rtv1->mlx->mlx_ptr, rtv1->mlx->img_ptr);
	mlx_destroy_window(rtv1->mlx->mlx_ptr, rtv1->mlx->win_ptr);
	free(rtv1->mlx->mlx_ptr);
	free(rtv1->mlx);
}

void			ft_free(t_rtv1 *rtv1)
{
	ft_free_mlx(rtv1);
	free(rtv1);
}
