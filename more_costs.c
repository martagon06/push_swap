/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_costs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 13:06:15 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/05 13:22:56 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	target_position(t_node *a, int index_b)
{
	int		pos;
	t_node	*current;
	int		best_pos;
	int		best_index;

	pos = 0;
	best_index = INT_MAX;
	best_pos = 0;
	current = a;
	while (current)
	{
		if (current->index > index_b && current->index < best_index)
		{
			best_index = current->index;
			best_pos = pos;
		}
		current = current->next;
		pos++;
	}
	if (best_index == INT_MAX)
		return (position_of_min_index(a));
	return (best_pos);
}

t_node	*get_node_by_index(t_node *top, int index)
{
	while (top)
	{
		if (top->index == index)
			return (top);
		top = top->next;
	}
	return (NULL);
}

int	position_of_min_index(t_node *a)
{
	int		pos;
	t_node	*current;
	int		min_index;
	int		min_pos;

	min_pos = 0;
	pos = 0;
	min_index = INT_MAX;
	min_pos = 0;
	current = a;
	while (current)
	{
		if (current->index < min_index)
		{
			min_index = current->index;
			min_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (min_pos);
}

int	get_position(t_node *top, t_node *target)
{
	int	pos;

	pos = 0;
	while (top && top != target)
	{
		top = top->next;
		pos++;
	}
	return (pos);
}

void	exec_moves(t_stack *a, t_stack *b, int cost_a, int cost_b, t_node *cheapest)
{
	int	pos;

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
	while (cost_a > 0)
	{
		ra(a);
		cost_a--;
	}
	while (cost_a < 0)
	{
		rra(a);
		cost_a++;
	}
	while (cost_b > 0)
	{
		rb(b);
		cost_b--;
	}
	while (cost_b < 0)
	{
		rrb(b);
		cost_b++;
	}
	while (b->top != cheapest)
	{
		pos = get_position(b->top, cheapest);
		if (pos <= b->size / 2)
			rb(b);
		else
			rrb(b);
	}
}
