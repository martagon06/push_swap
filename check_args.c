/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:59:09 by miguelmo          #+#    #+#             */
/*   Updated: 2025/08/20 18:11:52 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void print_error_and_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

int is_duplicate(t_stack *a, int value)
{
    t_node *cur = a->top;
    while (cur)
    {
        if (cur->value == value)
            return (1);
        cur = cur->next;
    }
    return (0);
}

static int is_valid_int(const char *str)
{
    long n = ft_atoi(str);
    int i = 0;
    if (str[0] == '-' || str[0] == '+')
        i++;
    if (str[i] == '\0')
        return (0);
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    if (n < INT_MIN || n > INT_MAX)
        return (0);
    return (1);
}

void parse_args(t_stack **a, int argc, char **argv)
{
    int i = 1;
    char **temporal = NULL;
    t_node *node;
    int value;

    if (argc == 2)
        temporal = ft_split(argv[1], ' ');
    if (temporal)
    {
        i = 0;
        while (temporal[i])
        {
            if (!is_valid_int(temporal[i]) || is_duplicate(*a, ft_atoi(temporal[i]))) // Cambio aquí
                print_error_and_exit();
            value = ft_atoi(temporal[i]);
            node = create_node(value);
            add_node(*a, node);
            i++;
        }
        free_temporal(temporal);
    }
    else
    {
        while (i < argc)
        {
            if (!is_valid_int(argv[i]) || is_duplicate(*a, ft_atoi(argv[i]))) // Cambio aquí
                print_error_and_exit();
            value = ft_atoi(argv[i]);
            node = create_node(value);
            add_node(*a, node);
            i++;
        }
    }
}
