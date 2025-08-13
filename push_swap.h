/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:10:08 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/13 19:39:29 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

// Estructuras
typedef struct s_node {
    int     value;
    int     index;
    int     cost_a;
    int     cost_b;
    int     total_cost;
    struct s_node    *next;
    struct s_node    *prev;
} t_node;

typedef struct s_stack
{
    t_node *top;
    t_node *bottom;
    int size;
} t_stack;

// Operaciones básicas
void    sa(t_stack *a);
void    sb(t_stack *b);
void    ss(t_stack *a, t_stack *b);
void    pa(t_stack *b, t_stack *a);
void    pb(t_stack *a, t_stack *b);
void    ra(t_stack *a);
void    rb(t_stack *b);
void    rr(t_stack *a, t_stack *b);
void    rra(t_stack *a);
void    rrb(t_stack *b);
void    rrr(t_stack *a, t_stack *b);

// Algoritmo principal y ordenaciones
void    rinyshort(t_stack *a, t_stack *b);
void    sort_2(t_stack *a);
void    sort_3(t_stack *a);
void    sort_4(t_stack *a, t_stack *b);
void    sort_5(t_stack *a, t_stack *b);
void    sort_big(t_stack *a, t_stack *b);

// Normalización e índices
void    normalize(t_stack *a);

// Costes y movimientos óptimos
void    calculate_costs(t_node *a, t_node *b);
void    move_cheapest(t_stack *a, t_stack *b);

// Utilidades de stacks y nodos
t_node  *create_node(int value);
void    free_stack(t_stack *stack);
void    push_min_to_b(t_stack *a, t_stack *b);
int     is_sorted(t_stack *a);

// Parsing y validación
int     ft_isspace(int c);
int     ft_atoi(const char *str);
void    ft_putchar_fd(char c, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putstr_fd(char *s, int fd);
char    **ft_split(char const *s, char c);
int     ft_isdigit(char c);
void    error_message(char *message);
int     valid_number(char *str);

// ...otros prototipos según tus archivos...

#endif