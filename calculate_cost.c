/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:51:26 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/05 13:22:55 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_stack_size(t_node *top)
{
	int	size;

	size = 0;
	while (top)
	{
		size++;
		top = top->next;
	}
	return (size);
}

static int	calc_cost(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

static void	set_costs(t_node *a, t_node *b, int size_a, int size_b)
{
	int	pos_b;
	int	pos_a;

	while (b)
	{
		pos_b = get_position(b, b);
		pos_a = target_position(a, b->index);
		b->cost_b = calc_cost(get_position(b, b), size_b);
		b->cost_a = calc_cost(pos_a, size_a);
		b->total_cost = abs(b->cost_a) + abs(b->cost_b);
		b = b->next;
	}
}

static t_node	*find_cheapest(t_node *b)
{
	t_node	*cheapest;
	int		min_cost;

	cheapest = NULL;
	min_cost = INT_MAX;
	while (b)
	{
		if (b->total_cost < min_cost)
		{
			min_cost = b->total_cost;
			cheapest = b;
		}
		b = b->next;
	}
	return (cheapest);
}

t_node	*calculate_cheapest(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	set_costs(a, b, size_a, size_b);
	return (find_cheapest(b));
}
