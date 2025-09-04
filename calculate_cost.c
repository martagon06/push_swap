/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:51:26 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/02 20:24:41 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_stack_size(t_node *top)
{
    int size = 0;
    while (top) {
        size++;
        top = top->next;
    }
    return size;
}

t_node *calculate_cheapest(t_node *a, t_node *b)
{
    int size_a = get_stack_size(a);
    int size_b = get_stack_size(b);
    t_node *tmp = b;
    t_node *cheapest = NULL;
    int min_cost = INT_MAX;

    while (tmp)
    {
        int pos_b = get_position(b, tmp);
        int pos_a = target_position(a, tmp->index);
        int cost_b = (pos_b <= size_b / 2) ? pos_b : pos_b - size_b;
        int cost_a = (pos_a <= size_a / 2) ? pos_a : pos_a - size_a;
        int total_cost = abs(cost_a) + abs(cost_b);

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

    return cheapest;
}

int get_position(t_node *top, t_node *target)
{
	int	pos;

	pos = 0;
	while (top && top != target)
	{
		top = top->next;
		pos++;
	}
	return pos;
}

int	target_position(t_node *a, int index_b)
{
    int pos = 0, best_index = INT_MAX, best_pos = 0;
    t_node *current = a;

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
        return position_of_min_index(a);

    return best_pos;
}

int position_of_min_index(t_node *a)
{
    int pos = 0, min_index = INT_MAX, min_pos = 0;
    t_node *current = a;

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
    return min_pos;
}

void exec_moves(t_stack *a, t_stack *b, int cost_a, int cost_b, t_node *cheapest)
{
    while (cost_a > 0 && cost_b > 0) { rr(a, b); cost_a--; cost_b--; }
    while (cost_a < 0 && cost_b < 0) { rrr(a, b); cost_a++; cost_b++; }
    while (cost_a > 0) { ra(a); cost_a--; }
    while (cost_a < 0) { rra(a); cost_a++; }
    while (cost_b > 0) { rb(b); cost_b--; }
    while (cost_b < 0) { rrb(b); cost_b++; }
    while (b->top != cheapest)
    {
        int pos = get_position(b->top, cheapest);
        if (pos <= b->size / 2) rb(b);
        else rrb(b);
    }
}

t_node *get_node_by_index(t_node *top, int index)
{
    while (top)
    {
        if (top->index == index)
            return top;
        top = top->next;
    }
    return NULL;
}