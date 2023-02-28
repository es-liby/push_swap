/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:43:43 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/19 09:28:41 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;

	if (argc == 1)
		exit(1);
	a = NULL;
	b = NULL;
	handle_error(&a, argv);
	if (is_sorted(a))
		exit(0);
	if (ft_lstsize(a) <= 3)
		sort_three_a(&a);
	else if (ft_lstsize(a) == 5)
		sort_five(&a, &b);
	else
		sort(&a, &b);
	return (0);
}
