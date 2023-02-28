/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sublibft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:08:00 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/09 10:27:37 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

void	ft_putstr(int fd, char *s)
{
	if (s == NULL)
		ft_putstr(fd, "(null)");
	else
		while (*s != '\0')
			ft_putchar(fd, *s++);
}

void	ft_putnbr(int fd, long nbr)
{
	if (nbr < 0)
	{
		ft_putchar(fd, '-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(fd, nbr / 10);
	ft_putchar(fd, nbr % 10 + '0');
}
