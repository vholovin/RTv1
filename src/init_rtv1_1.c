/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rtv1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:26:25 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/12 15:50:57 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

static t_camera	*init_camera(void)
{
	t_camera *camera;

	if (!(camera = (t_camera*)malloc(sizeof(t_camera))))
		error(0);
	camera->angle = 1.0;
	camera->rotate_xyz = (t_param){0.0, 0.0, 0.0};
	return (camera);
}

static int		read_endl(char *file_name)
{
	int		fd;
	size_t	endl;
	char	buf;

	fd = 0;
	endl = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		error(1);
	while (read(fd, &buf, 1))
	{
		if (buf == '\n')
			++endl;
	}
	close(fd);
	return (endl);
}

static t_file	*init_file(char *file_name)
{
	t_file	*file;
	char	**scene;

	if (!(file = (t_file*)malloc(sizeof(t_file))))
		error(0);
	file->endl = read_endl(file_name);
	if (!(scene = (char **)malloc(sizeof(char *) * (file->endl + 1))))
		error(0);
	return (file);
}

static t_mlx	*init_mlx(void)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		error(0);
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, W, H, "RTv1 - 42");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, W, H);
	mlx->ptr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	return (mlx);
}

t_rtv1			*init_rtv1(char *file_name)
{
	t_rtv1	*rtv1;

	if (!(rtv1 = (t_rtv1*)malloc(sizeof(t_rtv1))))
		error(0);
	rtv1->mlx = init_mlx();
	rtv1->file = init_file(file_name);
	rtv1->camera = init_camera();
	rtv1->ray = init_ray();
	rtv1->keys = init_keys();
	rtv1->light = NULL;
	rtv1->object = NULL;
	return (rtv1);
}
