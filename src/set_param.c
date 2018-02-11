/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:31:48 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/13 15:08:56 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static int	check_is_number(char *str)
{
	while (*str != '\0')
	{
		if (ft_isdigit(*str) == 0 && ft_isalpha(*str) != 0)
			return (0);
		str++;
	}
	return (1);
}

int			check_limit_number(int number, int min, int max)
{
	if (number >= min && number <= max)
		return (0);
	return (1);
}

t_color		multi_color(const char *desk, t_color color, char *str,
		size_t status)
{
	int		i;
	char	**split;

	i = 1;
	split = ft_strsplit(str, ' ');
	if (ft_strcmp(desk, split[0]) != 0)
		error(status);
	if (!split[1] || !split[2] || !split[3] || split[4])
		error(status);
	while (i <= 3)
	{
		if (check_is_number(split[i]) == 0)
			error(status);
		++i;
	}
	color.rgb.b = ft_atoi(split[1]);
	color.rgb.g = ft_atoi(split[2]);
	color.rgb.r = ft_atoi(split[3]);
	if (check_limit_number(ft_atoi(split[1]), 0, 255) != 0
			|| check_limit_number(ft_atoi(split[2]), 0, 255) != 0
			|| check_limit_number(ft_atoi(split[3]), 0, 255) != 0)
		error(status);
	free_split(split);
	return (color);
}

t_param		multi_param(const char *desk, t_param param, char *str,
		size_t status)
{
	int		i;
	char	**split;

	i = 1;
	split = ft_strsplit(str, ' ');
	if (ft_strcmp(desk, split[0]) != 0)
		error(status);
	if (!split[1] || !split[2] || !split[3] || split[4])
		error(status);
	else
	{
		while (i <= 3)
		{
			if (check_is_number(split[i]) == 0)
				error(status);
			++i;
		}
		param.x = (float)ft_atoi(split[1]);
		param.y = (float)ft_atoi(split[2]);
		param.z = (float)ft_atoi(split[3]);
	}
	free_split(split);
	return (param);
}

float		single_param(const char *desk, char *str, size_t status)
{
	float	param;
	char	**split;

	split = ft_strsplit(str, ' ');
	if (ft_strcmp(desk, split[0]) != 0)
		error(status);
	if (!split[1] || split[2])
		error(status);
	else
	{
		if (check_is_number(split[1]) == 0)
			error(status);
	}
	param = (float)ft_atoi(split[1]);
	if (param < 0)
		error(status);
	free_split(split);
	return (param);
}
