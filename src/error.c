/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:23:37 by vholovin          #+#    #+#             */
/*   Updated: 2017/09/22 19:23:43 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	error(int status)
{
	if (status == 0)
		ft_putendl("error maloc");
	else if (status == 1)
		perror("error open directory");
	else if (status == 2)
		perror("error open file");
	else if (status == 3)
		ft_putendl("use *.rtv1 file");
	else if (status == 4)
		ft_putendl("error close file");
	else if (status == 5)
		ft_putendl("error in description: camera");
	else if (status == 6)
		ft_putendl("error in description: scene");
	exit(0);
}
