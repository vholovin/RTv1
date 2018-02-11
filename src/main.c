/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:26:58 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:01:25 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

int		main(int ac, char **av)
{
	t_rtv1	*rtv1;

	if (ac == 2)
	{
		rtv1 = init_rtv1(av[1]);
		read_file(rtv1, av[1]);
		set_scene(rtv1);
		tutorial();
		mlx_hook(rtv1->mlx->win_ptr, 2, 1L << 0, key_press, rtv1);
		mlx_hook(rtv1->mlx->win_ptr, 3, 1L << 0, key_hook, rtv1);
		mlx_hook(rtv1->mlx->win_ptr, 17, 1L << 17, esc, rtv1);
		mlx_loop_hook(rtv1->mlx->mlx_ptr, expose_hook, rtv1);
		mlx_loop(rtv1->mlx->mlx_ptr);
	}
	else
		ft_putendl("Use RTv1 input file");
	return (0);
}
