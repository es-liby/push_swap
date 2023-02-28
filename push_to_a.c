/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:26:09 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 10:37:29 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_both_up(t_stack **a, t_stack **b, t_stack *s);
static void	move_both_down(t_stack **a, t_stack **b, t_stack *s);
static void	move_a_updown(t_stack **a, t_stack *s);
static void	move_b_updown(t_stack **b, t_stack *s);

void	push_to_a(t_stack **a, t_stack **b, t_stack *s)
{
	int	idx_a;
	int	idx_b;

	if (*b == NULL || s == NULL)
		return ;
	idx_a = s->index_a;
	idx_b = s->index_b;
	if (idx_a * idx_b > 0)
	{
		if (idx_a < 0)
			move_both_up(a, b, s);
		else
			move_both_down(a, b, s);
	}
	else
	{
		move_a_updown(a, s);
		move_b_updown(b, s);
	}
	pa(a, b);
}

static void	move_both_up(t_stack **a, t_stack **b, t_stack *s)
{
	int	idx_a;
	int	idx_b;
	int	min;

	idx_a = ft_abs(s->index_a);
	idx_b = ft_abs(s->index_b);
	min = ft_min(idx_a, idx_b);
	rrr_m(a, b, min);
	if (idx_b == min)
	{
		idx_a -= idx_b;
		rrs_machine(a, idx_a, rra);
	}
	else
	{
		idx_b -= idx_a;
		rrs_machine(b, idx_b, rrb);
	}
}

static void	move_both_down(t_stack **a, t_stack **b, t_stack *s)
{
	int	idx_a;
	int	idx_b;
	int	min;

	idx_a = ft_abs(s->index_a);
	idx_b = ft_abs(s->index_b);
	min = ft_min(idx_a, idx_b);
	rr_m(a, b, min);
	if (idx_b == min)
	{
		idx_a -= idx_b;
		rs_machine(a, idx_a, ra);
	}
	else
	{
		idx_b -= idx_a;
		rs_machine(b, idx_b, rb);
	}
}

static void	move_a_updown(t_stack **a, t_stack *s)
{
	int	idx_a;

	idx_a = s->index_a;
	if (idx_a > 0)
		rs_machine(a, idx_a, ra);
	else
		rrs_machine(a, ft_abs(idx_a), rra);
}

static void	move_b_updown(t_stack **b, t_stack *s)
{
	int	idx_b;

	idx_b = s->index_b;
	if (idx_b > 0)
		rs_machine(b, idx_b, rb);
	else
		rrs_machine(b, ft_abs(idx_b), rrb);
}
