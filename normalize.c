/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:08:51 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/12 13:37:33 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void normalize(t_stack *a)
{
    int size = a->size, i = 0, j, k, tmp;
    int *values = malloc(sizeof(int) * size);
    if (!values) return;
    t_node *cur = a->top;
    while (i < size) { values[i++] = cur->value; cur = cur->next; }
    for (i = 0; i < size - 1; i++)
        for (j = i + 1; j < size; j++)
            if (values[i] > values[j]) { tmp = values[i]; values[i] = values[j]; values[j] = tmp; }
    cur = a->top;
    while (cur)
    {
        k = 0;
        while (k < size)
        {
            if (cur->value == values[k]) { cur->index = k; break; }
            k++;
        }
        cur = cur->next;
    }
    free(values);
}