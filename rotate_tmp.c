/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_tmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:35:04 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 17:53:38 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rt(t_stack **t)
{
	t_stack	*first;
	t_stack	*last;

	if (ft_lstsize(*t) <= 1)
		return ;
	first = *t;
	last = ft_lstlast(*t);
	last->next = first;
	first->prev = last;
	*t = first->next;
	first->next = NULL;
}

void	rrt(t_stack **t)
{
	t_stack	*last;
	t_stack	*temp;

	if (ft_lstsize(*t) <= 1)
		return ;
	last = ft_lstlast(*t);
	temp = last->prev;
	last->next = *t;
	(*t)->prev = last;
	temp->next = NULL;
	last->prev = NULL;
	*t = last;
}
