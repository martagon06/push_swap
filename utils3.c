/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:10:58 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/08 19:05:32 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_min_to_b(t_stack *a, t_stack *b)
{
    t_node *current = a->top;
    int min = current->value;
    int pos = 0;
    int i = 0;

    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            pos = i;
        }
        current = current->next;
        i++;
    }

    if (pos <= a->size / 2)
    {
        while (pos-- > 0)
            ra(a);
    }
    else
    {
        while (pos++ < a->size)
            rra(a);
    }
    pb(a, b);
}

void push_to_b(t_node **a, t_node **b, int size)
{
    int pushed = 0;
    int i = 0;
    int median = size / 2;

    while (pushed < median && i < size)
    {
        if ((*a)->index >= median)
        {
            pb(a, b);  // push to stack_b
            pushed++;
        }
        else
            ra(a);     // rotate stack_a
        i++;
    }
}

