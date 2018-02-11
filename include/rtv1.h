/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 19:19:46 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/16 16:22:43 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "../libft/src/get_next_line.h"
# include "../libft/src/libft.h"
# include "../minilibX/mlx.h"
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# define MAX_DISTANCE 100000
# define W 1000
# define H 500

typedef struct		s_rgb
{
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
}					t_rgb;

typedef union		u_color
{
	int				value;
	t_rgb			rgb;
}					t_color;

typedef struct		s_param
{
	float			x;
	float			y;
	float			z;
}					t_param;

typedef struct		s_keys
{
	int				pos_up_down;
	int				pos_left_right;
	int				pos_forward_back;
}					t_keys;

typedef	struct		s_ray
{
	t_param			x;
	t_param			y;
	t_param			z;
	t_param			position;
	t_param			direction;
	t_param			normal;
	t_color			color;
	t_param			vector;
	float			distance;
}					t_ray;

typedef struct		s_object
{
	int				type;
	t_param			position;
	t_param			rotate;
	t_param			angle;
	t_color			color;
	unsigned		size;
	struct s_object	*next;
}					t_object;

typedef struct		s_camera
{
	t_param			position;
	t_param			rotate;
	float			angle;
	t_param			rotate_xyz;
}					t_camera;

typedef struct		s_file
{
	size_t			endl;
	char			**scene;
}					t_file;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct		s_rtv1
{
	t_mlx			*mlx;
	t_file			*file;
	t_camera		*camera;
	t_object		*light;
	t_object		*object;
	t_ray			*ray;
	t_keys			*keys;
}					t_rtv1;

t_rtv1				*init_rtv1(char *file_name);
t_ray				*init_ray(void);
t_keys				*init_keys(void);
t_param				multi_param(const char *desk, t_param param,
							char *str, size_t status);
t_param				ft_vector_sub(t_param v_1, t_param v_2);
t_param				ft_vector_norm(t_param v);
t_param				ft_vector_cross(t_param v_1, t_param v_2);
t_param				ft_vector_scale(t_param v, float n);
t_param				ft_lambert(t_rtv1 *rtv1, t_object *cross_object,
							t_object *cross_light);
t_param				ft_fong(t_rtv1 *rtv1, t_param vector, t_param color,
							float d);
t_color				multi_color(const char *desk, t_color color, char *str,
							size_t status);
t_object			*rotate_object(t_object *object);
t_object			*ft_cross_object(t_rtv1 *rtv1, t_object *object,
							t_param ray, t_param position);
void				read_file(t_rtv1 *rtv1, char *file_name);
void				set_scene(t_rtv1 *rtv1);
void				error(int status);
void				add_object_light(t_rtv1 *rtv1, size_t *i);
void				add_object_figure(t_rtv1 *rtv1, size_t *i, int type);
void				ft_ray_trace(t_rtv1 *rtv1, size_t i, size_t j);
void				camera_position(t_rtv1 *rtv1, float step);
void				camera_rotate(t_rtv1 *rtv1, float angle_x, float angle_y,
							float angle_z);
void				tutorial(void);
void				free_split(char **line_split);
void				ft_free(t_rtv1 *rtv1);
float				single_param(const char *desk, char *str, size_t status);
float				ft_vector_dot(t_param v_1, t_param v_2);
float				cross_plane(t_rtv1 *rtv1, t_object *object, t_param ray,
							t_param position);
float				cross_sphere(t_rtv1 *rtv1, t_object *object, t_param ray,
							t_param position);
float				cross_cylinder(t_rtv1 *rtv1, t_object *object, t_param ray,
							t_param position);
float				cross_cone(t_rtv1 *rtv1, t_object *object, t_param ray,
							t_param position);
int					check_limit_number(int number, int min, int max);
int					cross_shadow(t_rtv1 *rtv1, t_object *cross_object,
						t_object *cross_light, t_param position);
int					expose_hook(t_rtv1 *rtv1);
int					key_press(int keycode, t_rtv1 *rtv1);
int					key_hook(int keycode, t_rtv1 *rtv1);
int					esc(t_rtv1 *rtv1);
#endif
