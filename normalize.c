/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:08:51 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/13 19:39:34 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void assign_indexes(t_stack *a, int *values, int size)
{
    t_node *cur = a->top;
    int j;
    while (cur)
    {
        j = 0;
        while (j < size)
        {
            if (cur->value == values[j])
            {
                cur->index = j;
                break;
            }
            j++;
        }
        cur = cur->next;
    }
}

void normalize(t_stack *a)
{
    int size = a->size, i = 0, j, tmp;
    int *values = malloc(sizeof(int) * size);
    if (!values) return;
    t_node *cur = a->top;
    while (i < size)
    {
        values[i] = cur->value;
        cur = cur->next;
        i++;
    }
    i = 0;
    while (i < size - 1)
    {
        j = i + 1;
        while (j < size)
        {
            if (values[i] > values[j])
            {
                tmp = values[i];
                values[i] = values[j];
                values[j] = tmp;
            }
            j++;
        }
        i++;
    }
    assign_indexes(a, values, size);
    free(values);
}