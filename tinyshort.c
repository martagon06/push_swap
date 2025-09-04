/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinyshort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:10:16 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/22 17:52:15 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rinyshort(t_stack *a, t_stack *b)
{
    if (a->size == 2)
        sort_2(a);
    else if (a->size == 3)
        sort_3(a);
    else if (a->size == 4)
        sort_4(a, b);
    else if (a->size == 5)
        sort_5(a, b);
    else
        sort_big(a, b);
}

void sort_2(t_stack *a)
{
    if (a->top->value > a->top->next->value)
        sa(a);
}

void sort_3(t_stack *a)
{
    int first = a->top->value;
    int second = a->top->next->value;
    int third = a->bottom->value;
    if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
    else if (first < second && second > third && first > third)
        rra(a);
}


void sort_4(t_stack *a, t_stack *b)
{
    push_min_to_b(a, b);
    sort_3(a);
    pa(b, a);
}

void sort_5(t_stack *a, t_stack *b)
{
    push_min_to_b(a, b);
    push_min_to_b(a, b);
    sort_3(a);
    pa(b, a);
    pa(b, a);
}

void sort_big(t_stack *a, t_stack *b)
{
    int pushed = 0;
    int size = a->size;
    int chunk = (size <= 100) ? 15 : 30;

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
    if (a->size == 3 && !is_sorted(a))
        sort_3(a);
    while (b->top)
    {
        t_node *cheapest = calculate_cheapest(a->top, b->top);
        if (!cheapest) break;
        exec_moves(a, b, cheapest->cost_a, cheapest->cost_b, cheapest);
        pa(a, b);
    }
    rotate_min_to_top(a);
}

void rotate_min_to_top(t_stack *a)
{
    int pos = get_position(a->top, get_node_by_index(a->top, 0));
    int size = a->size;

    if (pos <= size / 2)
        while (a->top->index != 0)
            ra(a);
    else
        while (a->top->index != 0)
            rra(a);
}

int is_sorted(t_stack *s)
{
    t_node *cur = s->top;
    while (cur && cur->next)
    {
        if (cur->index > cur->next->index)
            return 0;
        cur = cur->next;
    }
    return 1;
}
