/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:27:44 by vholovin          #+#    #+#             */
/*   Updated: 2017/09/22 19:27:47 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static void	read_scene(int fd, t_rtv1 *rtv1)
{
	size_t	i;
	char	*line;
	char	**scene;

	if (!(scene = (char **)malloc(sizeof(char *) * (rtv1->file->endl + 1))))
		error(0);
	i = 0;
	while (get_next_line(fd, &line) == 1 || i <= rtv1->file->endl)
	{
		if (!(scene[i] = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1))))
			error(0);
		scene[i] = ft_strcpy(scene[i], line);
		++i;
		free(line);
	}
	rtv1->file->scene = scene;
}

void		read_file(t_rtv1 *rtv1, char *file_name)
{
	int		fd;

	fd = open(file_name, O_DIRECTORY);
	if (fd >= 0)
		error(1);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error(2);
	if (ft_strcmp(ft_strchr(file_name, '.'), ".rtv1") != 0)
		error(3);
	read_scene(fd, rtv1);
	if (close(fd) == -1)
		error(4);
}
