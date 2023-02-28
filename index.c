/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabkadri <iabkadri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:42:59 by iabkadri          #+#    #+#             */
/*   Updated: 2023/01/19 09:19:59 by iabkadri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_pos_largest(t_stack *s, t_stack *t, int size, int *pos);
static void	put_index_b(t_stack *s, t_stack *t, int size);
static int	pos_largest(t_stack **a);

void	set_index_b(t_stack **b, t_stack **a)
{
	t_stack	*s;
	t_stack	*t;
	int		*arr;

	if (*b == NULL)
		return ;
	s = *b;
	t = ft_lstlast(*b);
	put_index_b(s, t, ft_lstsize(*b));
	s = *b;
	arr = transfer_to_array(*a, *b);
	while (s)
	{
		s->index_a = put_index_a(a, s, arr);
		s = s->next;
	}
	free(arr);
}

static void	put_index_b(t_stack *s, t_stack *t, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size - 1;
	while (i <= j && s && t)
	{
		t->index_b = j - size;
		s->index_b = i;
		s = s->next;
		t = t->prev;
		j--;
		i++;
	}
}

int	put_index_a(t_stack **a, t_stack *s, int *arr)
{
	int	size;
	int	i;
	int	j;

	size = ft_lstsize(*a);
	if (s->n < arr[0] && s->n > arr[size - 1])
		return (0);
	i = 0;
	j = size - 1;
	while (i <= j)
	{
		if (s->n > arr[i] && s->n < arr[i + 1])
			return (i + 1);
		if (s->n < arr[j] && s->n > arr[j - 1])
			return (j - size);
		i++;
		j--;
	}
	return (pos_largest(a));
}

static int	pos_largest(t_stack **a)
{
	t_stack	*s;
	t_stack	*t;
	int		pos;

	if ((*a)->n == get_largest(*a))
		return (1);
	s = *a;
	t = ft_lstlast(*a);
	if (t->n == get_largest(*a) || s->n == get_smallest(s))
		return (0);
	set_pos_largest(s, t, ft_lstsize(*a), &pos);
	return (pos);
}

static void	set_pos_largest(t_stack *s, t_stack *t, int size, int *pos)
{
	int	largest;
	int	i;
	int	j;

	*pos = 1;
	largest = s->n;
	s = s->next;
	i = 0;
	j = size;
	while (++i <= --j && s && t)
	{
		if (largest < t->n)
		{
			largest = t->n;
			*pos = j - size + 1;
		}
		if (largest < s->n)
		{
			largest = s->n;
			*pos = i + 1;
		}
		s = s->next;
		t = t->prev;
	}
}
