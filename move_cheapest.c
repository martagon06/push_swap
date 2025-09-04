/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 13:47:40 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/04 19:34:30 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_cheapest(t_stack *a, t_stack *b)
{
	t_node	*cheapest;
	t_node	*tmp;
	int		min;

	cheapest = NULL;
	tmp = b->top;
	min = INT_MAX;
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
	exec_moves(a, b, cheapest->cost_a, cheapest->cost_b, cheapest);
	pa(b, a);
}
