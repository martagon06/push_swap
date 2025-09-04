/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:57:31 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/22 13:49:19 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack *src, t_stack *dest)
{
    t_node *node;

    if (!src || !src->top)
        return;
    node = src->top;
    src->top = node->next;
    if (src->top)
        src->top->prev = NULL;
    else
        src->bottom = NULL;
    src->size--;
    node->next = dest->top;
    node->prev = NULL;
    if (dest->top)
        dest->top->prev = node;
    else
        dest->bottom = node;
    dest->top = node;
    dest->size++;
}


void pa(t_stack *a, t_stack *b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void pb(t_stack *a, t_stack *b)
{
    push(a, b);
    write(1, "pb\n", 3);
}