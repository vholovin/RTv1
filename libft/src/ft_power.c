/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 17:00:45 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/29 14:27:58 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int ch;

	if (power == 0)
		return (1);
	ch = nb;
	while (power > 1)
	{
		nb = nb * ch;
		power--;
	}
	return (nb);
}
