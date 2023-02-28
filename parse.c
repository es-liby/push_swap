/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:06:51 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/19 09:14:10 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		exit(1);
	}
	ft_lstadd_back(a, stk);
}

void	handle_error(t_stack **a, char **av)
{
	char	**sp;
	int		i;

	while (*++av)
	{
		i = -1;
		sp = ft_split(*av, ' ');
		if (sp == NULL)
		{
			ft_free(*a);
			exit(1);
		}
		while (sp[++i])
		{
			if (check_args(sp[i]) == 0)
			{
				ft_free(*a);
				free_tab(sp, i);
				ft_error();
			}
			fill_stack(a, sp, i);
		}
		free_tab(sp, i);
	}
	ft_duplicate(a);
}
