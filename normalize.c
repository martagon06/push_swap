/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:08:51 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/04 19:44:27 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	assign_indexes(t_stack *a, int *values, int size)
{
	t_node	*cur;
	int		j;

	cur = a->top;
	while (cur)
	{
		j = 0;
		while (j < size)
		{
			if (cur->value == values[j])
			{
				cur->index = j;
				break ;
			}
			j++;
		}
		cur = cur->next;
	}
}

void	normalize(t_stack *a)
{
	int		size;
	int		i;
	int		j;
	int		tmp;
	int		*values;
	t_node	*cur;

	i = 0;
	size = a->size;
	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	cur = a->top;
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
