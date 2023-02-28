/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:46:50 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/19 09:20:04 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_fprintf.h"

/* structure for storing the longest increasing subsequence*/
typedef struct s_lis
{
	int	*arr;
	int	len;
}	t_lis;

/* swap operations */
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

/* push operations */
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

/* rotate operations */
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

/* reverse rotate operations */
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

void	sort(t_stack **a, t_stack **b);
t_stack	*best_element(t_stack *b);
int		*transfer_to_array(t_stack *s, t_stack *a);

t_lis	*find_lis(int *arr, int size);

/* indexing */
void	set_index_b(t_stack **b, t_stack **a);
int		put_index_a(t_stack **a, t_stack *s, int *arr);
void	put_smallest_on_top(t_stack **temp);
void	put_smallest_on_top_a(t_stack **a);
int		get_smallest(t_stack *stk);
int		get_largest(t_stack *stk);
void	push_to_a(t_stack **a, t_stack **b, t_stack *s);

/* math */
int		ft_abs(int x);
int		ft_min(int a, int b);

/* operations of temp */
void	rt(t_stack **t);
void	rrt(t_stack **t);

/* machines for rrr and rr operations */
void	rrr_m(t_stack **a, t_stack **b, int counter);
void	rr_m(t_stack **a, t_stack **b, int counter);

/* machines for ra, rb, rra, and rrb operations */
void	rs_machine(t_stack **stk, int counter, void (*rs)(t_stack **));
void	rrs_machine(t_stack **stk, int counter, void (*rrs)(t_stack **));

void	sort_five(t_stack **a, t_stack **b);
void	sort_three_a(t_stack **a);
int		a_is_sorted(t_stack *a);

/* parsing */
void	handle_error(t_stack **a, char **av);
void	ft_error(void);
void	ft_free(t_stack *stk);
int		check_args(char *sp);
void	ft_duplicate(t_stack **a);

#endif