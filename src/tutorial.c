/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tutorial.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 14:56:29 by vholovin          #+#    #+#             */
/*   Updated: 2017/10/13 14:56:50 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rtv1.h"

void	tutorial(void)
{
	ft_putstr("\
CONTROLS:\n\
Move camera:\n\
	OY_up:          Key: w\n\
	OY_down:        Key: s\n\
	OZ_up:          Key: shift\n\
	OZ_down:        Key: ctrl\n\
	OX_up:          Key: d\n\
	OX_down:        Key: a\n\
Rotate camera:\n\
	Up:             Key: up\n\
	Down:           Key: down\n\
	Left:           Key: left\n\
	Right:          Key: right\n\
	Clockwise:      Key: >\n\
	Anticlock:      Key: <\n\
Zoom:\n\
	Zoom +:         Key: +\n\
	Zoom -:         Key: -\n\
\n\
	Exit:           Key: esc\n\
");
}
