/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:29:01 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/09 11:29:01 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(t_stack *stk)
{
	t_stack	*temp;

	while (stk)
	{
		temp = stk;
		stk = stk->next;
		free(temp);
	}
}

void	ft_error(void)
{
	ft_fprintf(2, "Error\n");
	exit(1);
}

int	check_args(char *sp)
{
	int	i;

	i = 0;
	if (sp[i] == '-' || sp[i] == '+')
		i++;
	if (ft_isdigit(sp[i]) == 0)
		return (0);
	while (sp[i])
	{
		if (ft_isdigit(sp[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	ft_duplicate(t_stack **a)
{
	t_stack	*stk;
	t_stack	*nxt;

	stk = *a;
	while (stk)
	{
		nxt = stk->next;
		while (nxt)
		{
			if (nxt->n == stk->n)
			{
				ft_free(*a);
				ft_error();
			}
			nxt = nxt->next;
		}
		stk = stk->next;
	}
}
