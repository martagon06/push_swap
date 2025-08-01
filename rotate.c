/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 14:30:52 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/31 16:14:31 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack *stack)
{
    t_node *first_node;

    if (!stack || stack->size < 2)
        return;
    first_node = stack->top;
    
    stack->top = first_node->next;
    stack->top->prev = NULL;

    first_node->next = NULL;
    first_node->prev = stack->bottom;
    stack->bottom->next = first_node;
    stack->bottom = first_node;
}

void ra(t_stack *a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void rb(t_stack *b)
{
    rotate(rb);
    write (1, "rb\n", 3);
}

