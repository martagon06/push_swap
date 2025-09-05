/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 18:08:51 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/05 13:03:38 by miguelmo         ###   ########.fr       */
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

static void	fill_values_array(t_stack *a, int *values, int size)
{
	t_node	*cur;
	int		i;

	cur = a->top;
	i = 0;
	while (i < size)
	{
		values[i] = cur->value;
		cur = cur->next;
		i++;
	}
}

static void	sort_values(int *values, int size)
{
	int	i;
	int	j;
	int	tmp;

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
}

void	normalize(t_stack *a)
{
	int		size;
	int		*values;

	size = a->size;
	values = malloc(sizeof(int) * size);
	if (!values)
		return ;
	fill_values_array(a, values, size);
	sort_values(values, size);
	assign_indexes(a, values, size);
	free(values);
}
