/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:31:40 by iabkadri          #+#    #+#             */
/*   Updated: 2022/10/20 10:02:53 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	count_nbr(long nb);

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	size_t	cnt;

	nb = n;
	cnt = count_nbr(nb);
	str = malloc(cnt + 1);
	if (str == NULL)
		return (NULL);
	str[cnt] = '\0';
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		str[--cnt] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}

static size_t	count_nbr(long nb)
{
	size_t	cnt;

	cnt = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		cnt++;
		nb *= -1;
	}
	while (nb != 0)
	{
		cnt++;
		nb /= 10;
	}
	return (cnt);
}
