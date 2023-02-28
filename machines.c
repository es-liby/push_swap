/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   machines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:52:19 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/13 11:52:57 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rs_machine(t_stack **stk, int counter, void (*rs)(t_stack **))
{
	while (counter-- > 0)
		(*rs)(stk);
}

void	rrs_machine(t_stack **stk, int counter, void (*rrs)(t_stack **))
{
	while (counter-- > 0)
		(*rrs)(stk);
}

void	rrr_m(t_stack **a, t_stack **b, int counter)
{
	while (counter-- > 0)
		rrr(a, b);
}

void	rr_m(t_stack **a, t_stack **b, int counter)
{
	while (counter-- > 0)
		rr(a, b);
}
