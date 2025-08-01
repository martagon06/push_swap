/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinyshort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:10:16 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/31 16:15:05 by miguelmo         ###   ########.fr       */
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
