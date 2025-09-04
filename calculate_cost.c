/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:51:26 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/04 19:31:52 by miguelmo         ###   ########.fr       */
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

t_node	*calculate_cheapest(t_node *a, t_node *b)
{
	int		size_a;
	int		size_b;
	t_node	*tmp;
	t_node	*cheapest;
	int		min_cost;
	int		pos_b;
	int		pos_a;
	int		cost_b;
	int		cost_a;
	int		total_cost;

	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	tmp = b;
	cheapest = NULL;
	min_cost = INT_MAX;
	while (tmp)
	{
		pos_b = get_position(b, tmp);
		pos_a = target_position(a, tmp->index);
		cost_b = (pos_b <= size_b / 2) ? pos_b : pos_b - size_b;
		cost_a = (pos_a <= size_a / 2) ? pos_a : pos_a - size_a;
		total_cost = abs(cost_a) + abs(cost_b);
		tmp->cost_a = cost_a;
		tmp->cost_b = cost_b;
		tmp->total_cost = total_cost;
		if (total_cost < min_cost)
		{
			min_cost = total_cost;
			cheapest = tmp;
		}
		tmp = tmp->next;
	}
	return (cheapest);
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
