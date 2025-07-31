/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:10:58 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/31 16:11:41 by miguelmo         ###   ########.fr       */
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
