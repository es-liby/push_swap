/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 09:14:36 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/14 10:45:44 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_tab(char **sp, int i)
{
	int	j;

	j = 0;
	while (j <= i)
		free(sp[j++]);
	free(sp);
}

void	fill_stack(t_stack **a, char **sp, int i)
{
	t_stack	*stk;
	int		val;

	val = ft_atoi(sp[i]);
	if (val == -1 && ft_strlen(sp[i]) > 2)
	{
		ft_free(*a);
		free_tab(sp, i);
		ft_error();
	}
	stk = ft_lstnew(val);
	if (stk == NULL)
	{
		free_tab(sp, i);
		ft_free(*a);
		ft_error();
	}
	ft_lstadd_back(a, stk);
}
