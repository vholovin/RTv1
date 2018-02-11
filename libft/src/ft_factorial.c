/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorual.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/29 12:33:58 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/29 14:34:29 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int nb)
{
	if (nb < 0 || nb > 13)
		return (0);
	else
	{
		if (nb > 1)
		{
			return (nb * ft_factorial(nb - 1));
		}
		else
		{
			return (1);
		}
	}
}
