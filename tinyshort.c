/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tinyshort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:10:16 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/04 19:55:32 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rinyshort(t_stack *a, t_stack *b)
{
	if (a->size == 2)
		sort_2(a);
	else if (a->size == 3)
		sort_3(a);
	else if (a->size == 4)
		sort_4(a, b);
	else if (a->size == 5)
		sort_5(a, b);
	else
		sort_big(a, b);
}

void	sort_2(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}

void	sort_3(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->top->value;
	second = a->top->next->value;
	third = a->bottom->value;
	if (first > second && second < third && first < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && second < third && first > third)
		ra(a);
	else if (first < second && second > third && first < third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && second > third && first > third)
		rra(a);
}

void	sort_4(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	sort_3(a);
	pa(b, a);
}

void	sort_5(t_stack *a, t_stack *b)
{
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_3(a);
	pa(b, a);
	pa(b, a);
}
