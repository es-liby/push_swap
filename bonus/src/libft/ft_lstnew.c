/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:18:08 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/09 10:38:17 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_stack	*ft_lstnew(int n)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node != NULL)
	{
		new_node->n = n;
		new_node->next = NULL;
	}
	return (new_node);
}
