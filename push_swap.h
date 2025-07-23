/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:10:08 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/23 18:45:22 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_node {
    int     value;
    t_node    *next;
    t_node    *prev;
} t_node;

typedef struct s_satck {
    int size;
    t_node  *top;
    t_node  *bottom;
} t_stack;

typedef struct t_context {
    int count;
    t_stack *a;
    t_stack *b;
} s_context;


#endif