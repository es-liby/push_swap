/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:07:23 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/09 10:47:30 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fprintf.h"

void	ft_fprintf(int fd, const char *format, ...)
{
	va_list	ap;

	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			ft_putchar(fd, *format);
		else
			ft_handle(fd, *++format, ap);
		format++;
	}
	va_end(ap);
}
