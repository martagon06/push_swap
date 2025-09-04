/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:47:33 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/20 18:11:58 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *create_stack(void)
{
    t_stack *stack;
    stack = malloc(sizeof(t_stack));
    if(!stack)
        return NULL;
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
    return stack;
}

t_node      *create_node(int num)
{
    t_node *node = malloc(sizeof(t_node));
    if (!node)
        return NULL;
    node->value = num;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void    add_node(t_stack *stack, t_node *new)
{
    if(!stack->top)
    {
        stack->top = new;
        stack->bottom = new;
    }
    else
    {
        stack->bottom->next = new;
        new->prev = stack->bottom;
        stack->bottom = new;
    }
    stack->size++;
}

void free_stack(t_stack *stack)
{
    t_node *current = stack->top;
    t_node *next;

    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void    free_temporal(char **temporal)
{
    int i = 0;
    while (temporal[i])
    {
        free(temporal[i]);
        i++;
    }
    free(temporal); 
}