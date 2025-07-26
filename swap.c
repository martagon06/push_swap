/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 20:14:00 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/26 20:19:15 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack **b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    sa(a);
    sb(b);
    write(1, "ss\n", 3);
}