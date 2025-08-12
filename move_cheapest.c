/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:47:40 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/12 14:15:06 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

static void	rotate_a(t_stack *a, int *cost_a)
{
	while (*cost_a > 0)
	{
		ra(a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		rra(a);
		(*cost_a)++;
	}
}

static void	rotate_b(t_stack *b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rb(b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		rrb(b);
		(*cost_b)++;
	}
}

static void	exec_moves(t_stack *a, t_stack *b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(a, b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(a, b);
		cost_a++;
		cost_b++;
	}
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
}

void	move_cheapest(t_stack *a, t_stack *b)
{
	t_node	*cheapest = NULL;
	t_node	*tmp = b->top;
	int		min = INT_MAX;

	while (tmp)
	{
		if (tmp->total_cost < min)
		{
			min = tmp->total_cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	if (!cheapest)
		return ;
	exec_moves(a, b, cheapest->cost_a, cheapest->cost_b);
	pa(b, a);
}