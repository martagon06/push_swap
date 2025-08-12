/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:51:26 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/12 14:15:08 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_stack_size(t_node *top)
{
    int size = 0;
    while (top) { size++; top = top->next; }
    return size;
}

void calculate_costs(t_node *a, t_node *b)
{
    int size_a = get_stack_size(a);
    int size_b = get_stack_size(b);
    t_node *tmp = b;
    while (tmp)
    {
        int pos_b = get_position(b, tmp);
        int pos_a = target_position(a, tmp->index);
        tmp->cost_b = (pos_b <= size_b / 2) ? pos_b : pos_b - size_b;
        tmp->cost_a = (pos_a <= size_a / 2) ? pos_a : pos_a - size_a;
        tmp->total_cost = abs(tmp->cost_a) + abs(tmp->cost_b);
        tmp = tmp->next;
    }
}

static int get_position(t_node *top, t_node *target)
{
    int pos = 0;
    while (top && top != target)
    {
        top = top->next;
        pos++;
    }
    return pos;
}

static int target_position(t_node *a, int index_b)
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

static int position_of_min_index(t_node *a)
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