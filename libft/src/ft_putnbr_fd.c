/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vholovin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 19:01:14 by vholovin          #+#    #+#             */
/*   Updated: 2016/12/27 20:59:25 by vholovin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_out(int fd)
{
	ft_putchar_fd('-', fd);
	ft_putchar_fd('2', fd);
	ft_putchar_fd('1', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('7', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
	ft_putchar_fd('3', fd);
	ft_putchar_fd('6', fd);
	ft_putchar_fd('4', fd);
	ft_putchar_fd('8', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_out(fd);
	else
	{
		if (n == 0)
		{
			ft_putchar_fd('0', fd);
		}
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd(-n, fd);
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
		if (n > 0 && n < 10)
			ft_putchar_fd('0' + n, fd);
	}
}
