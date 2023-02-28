/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:46:04 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 10:46:05 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include "libft.h"
# include "ft_fprintf.h"
# include "get_next_line.h"

void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

int		a_is_sorted(t_stack *a);
int		b_is_sorted(t_stack *b);

void	ft_error(void);
void	ft_exit(t_stack *a, t_stack *b);
void	ft_free(t_stack *stk);
int		check_args(char *sp);
void	ft_duplicate(t_stack **a);
void	free_tab(char **sp, int i);
void	fill_stack(t_stack **a, char **sp, int i);

#endif