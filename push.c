/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:57:31 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/26 20:19:10 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(t_stack **src, t_stack **dest)
{
    t_stack *temporal;

    if (*src == NULL)
        return;
    temporal = src;
    *src = (*src)->next;
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
