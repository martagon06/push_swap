/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:57:31 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/30 14:54:00 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **src, t_stack **dest)
{
    t_node *temporal;

    if (*src == NULL || !(*src)->top)
        return;
    temporal = (*src)->top;
    *src = (*src)->top;
    temporal->next = *dest;
    *dest = temporal;
}

void    pa(t_stack **a, t_stack **b)
{
    push(b, a);
    write(1, "pa\n", 3);
}

void    pb(t_stack **a, t_stack **b)
{
    push(a, b);
    write(1, "pb\n", 3);
}
