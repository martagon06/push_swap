/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 12:01:44 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/06 12:37:32 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_stack *a, t_stack *b,
			int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	rotate_single_a(t_stack *a, int *cost)
{
	while (*cost > 0)
	{
		ra(a);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rra(a);
		(*cost)++;
	}
}

static void	rotate_single_b(t_stack *b, int *cost)
{
	while (*cost > 0)
	{
		rb(b);
		(*cost)--;
	}
	while (*cost < 0)
	{
		rrb(b);
		(*cost)++;
	}
}

void	exec_moves(t_stack *a, t_stack *b, t_node *cheapest)
{
	int	pos;

	rotate_both(a, b, &cheapest->cost_a, &cheapest->cost_b);
	rotate_single_a(a, &cheapest->cost_a);
	rotate_single_b(b, &cheapest->cost_b);
	while (b->top != cheapest)
	{
		pos = get_position(b->top, cheapest);
		if (pos <= b->size / 2)
			rb(b);
		else
			rrb(b);
	}
}
