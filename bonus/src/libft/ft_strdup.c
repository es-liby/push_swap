/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:21:50 by iabkadri          #+#    #+#             */
/*   Updated: 2022/10/19 17:23:18 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	size;

	size = ft_strlen(s1) + 1;
	p = malloc(size);
	if (p != NULL)
		ft_strlcpy(p, s1, size);
	return (p);
}
