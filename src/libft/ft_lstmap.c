/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:38:27 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/09 10:37:41 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_lstmap(t_stack *stk, int (*f)(int), void (*del)(int))
{
	t_stack	*header;
	t_stack	*new;

	header = NULL;
	while (stk != NULL)
	{
		new = ft_lstnew((*f)(stk->n));
		if (new == NULL)
		{
			ft_lstclear(&header, del);
			break ;
		}
		ft_lstadd_back(&header, new);
		stk = stk->next;
	}
	return (header);
}
