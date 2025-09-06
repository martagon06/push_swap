/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 19:55:11 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/06 12:37:53 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (15);
	else
		return (30);
}

static void	push_chunks(t_stack *a, t_stack *b, int chunk)
{
	int	pushed;

	pushed = 0;
	while (a->size > 3 && a->top)
	{
		if (a->top->index <= pushed + chunk)
		{
			pb(a, b);
			if (b->top && b->top->index < pushed + chunk / 2)
				rb(b);
			pushed++;
		}
		else
			ra(a);
	}
}

static void	move_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*cheapest;

	while (b->top)
	{
		cheapest = calculate_cheapest(a->top, b->top);
		if (!cheapest)
			break ;
		exec_moves(a, b, cheapest);
		pa(a, b);
	}
}

void	sort_big(t_stack *a, t_stack *b)
{
	int	chunk;

	chunk = get_chunk_size(a->size);
	push_chunks(a, b, chunk);
	if (a->size == 3 && !is_sorted(a))
		sort_3(a);
	move_back_to_a(a, b);
	rotate_min_to_top(a);
}

void	rotate_min_to_top(t_stack *a)
{
	int	pos;
	int	size;

	pos = get_position(a->top, get_node_by_index(a->top, 0));
	size = a->size;
	if (pos <= size / 2)
		while (a->top->index != 0)
			ra(a);
	else
		while (a->top->index != 0)
			rra(a);
}
