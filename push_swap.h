/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:10:08 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/22 19:37:47 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct t_node {
    int     value;
    int     index;
    int     *next;
} s_node;

typedef struct t_satck {
    int size;
    s_node  *top;
    s_node  *bottom;
} s_stack;

typedef struct t_context {
    int count;
    s_stack a;
    s_stack b;
} s_context;


#endif