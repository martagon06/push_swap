/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:08:51 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/08 19:05:31 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void normalize(t_stack *a)
{
    int size = a->size;
    int *values = malloc(sizeof(int) * size);
    if (!values)
        return;
    t_node *cur = a->top;
    for (int i = 0; i < size; i++)
    {
        values[i] = cur->value;
        cur = cur->next;
    }
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (values[i] > values[j])
            {
                int tmp = values[i];
                values[i] = values[j];
                values[j] = tmp;
            }
        }
    }
    cur = a->top;
    while (cur)
    {
        for (int i = 0; i < size; i++)
            if (cur->value == values[i])
                cur->index = i;
        cur = cur->next;
    }
    free(values);
}