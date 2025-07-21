/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:08:48 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/17 20:40:42 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv)
{
    int *stack_a;
    int *stack_b;

    argc -= 1; //tambien cuenta el nombre del programa, que es el argumento 0;

    if (argc < 2)
    {
        write (2, "Error\n", 6);
        return 1;
    }
    
    

}