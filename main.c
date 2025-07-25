/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:08:48 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/25 19:01:39 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    a = create_stack();
    b = crate_stack();

    if (argc < 2)
    {
        write (2, "Error\n", 6);
        return 1;
    }
    parse_args(&a, argc, argv);
    show_stack(a);
    free(a);
    return 0;
}