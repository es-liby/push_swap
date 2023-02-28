/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:17:54 by iabkadri          #+#    #+#             */
/*   Updated: 2022/10/24 09:42:48 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count != 0)
		if ((size_t)(-1) / count < size)
			return (NULL);
	ptr = malloc(count * size);
	if (ptr != NULL)
		ft_memset(ptr, 0, count * size);
	return (ptr);
}
