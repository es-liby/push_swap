/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:20:05 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/19 09:34:56 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	handle_error(t_stack **a, char **av);
static int	is_sorted(t_stack *a);
static int	handle_opts(t_stack **a, t_stack **b, char *opt);

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	*opt;

	if (argc == 1)
		exit(1);
	a = NULL;
	b = NULL;
	handle_error(&a, argv);
	opt = get_next_line(0);
	while (opt)
	{
		if (handle_opts(&a, &b, opt) == -1)
			ft_exit(a, b);
		free(opt);
		opt = get_next_line(0);
	}
	if (is_sorted(a) && b == NULL)
		ft_fprintf(1, "OK\n");
	else
		ft_fprintf(1, "KO\n");
	return (0);
}

static void	handle_error(t_stack **a, char **av)
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

static int	handle_opts(t_stack **a, t_stack **b, char *opt)
{
	if (ft_strcmp(opt, "sa\n") == 0)
		sa(*a);
	else if (ft_strcmp(opt, "sb\n") == 0)
		sb(*b);
	else if (ft_strcmp(opt, "ss\n") == 0)
		ss(*a, *b);
	else if (ft_strcmp(opt, "pa\n") == 0)
		pa(a, b);
	else if (ft_strcmp(opt, "pb\n") == 0)
		pb(b, a);
	else if (ft_strcmp(opt, "ra\n") == 0)
		ra(a);
	else if (ft_strcmp(opt, "rb\n") == 0)
		rb(b);
	else if (ft_strcmp(opt, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(opt, "rra\n") == 0)
		rra(a);
	else if (ft_strcmp(opt, "rrb\n") == 0)
		rrb(b);
	else if (ft_strcmp(opt, "rrr\n") == 0)
		rrr(a, b);
	else
		return (-1);
	return (1);
}

static int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->n > a->next->n)
			return (0);
		a = a->next;
	}
	return (1);
}
