/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_costs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:51:26 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/08 19:05:25 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calculate_costs(t_node *a, t_node *b)
{
    int size_a = 0;
    int size_b = 0;
    t_node *tmp;
    tmp = a;
    while (tmp)
    {
        size_a++;
        tmp = tmp->next;
    }
    tmp = b;
    while (tmp)
    {
        size_b++;
        tmp = tmp->next;
    }
    tmp = b;
    while (tmp)
    {
        int pos_b = get_position(b, tmp);
        int pos_a = target_position(a, tmp->index);

        int cost_b = (pos_b <= size_b / 2) ? pos_b : pos_b - size_b;
        int cost_a = (pos_a <= size_a / 2) ? pos_a : pos_a - size_a;
        printf("Nodo %d: cost_a = %d, cost_b = %d\n", tmp->value, cost_a, cost_b);

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
    int pos = 0;
    int best_index = __INT_MAX__;
    int best_pos = 0;
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
    if (best_index == __INT_MAX__)
        return position_of_min_index(a);

    return best_pos;
}

static int position_of_min_index(t_node *a)
{
    int pos = 0;
    int min_index = __INT_MAX__;
    int min_pos = 0;
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