/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:59:09 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/24 20:15:42 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void parse_args(t_stack *a, int argc, char **argv)
{
 int i;
 
 i = 1;

 while (i < argc)
 {
   int valor;

   valor = ft_atoi(argv[i]);
   t_node *node = create_node(valor);
   if(!node)
   {
      write(1, "Error\n", 6);
      return 1;
   }
   add_node(a, node);
   i++;
 }
}

void show_stack(t_stack *stack)
{
   wtite(1, "Stack construido\n", 17);
   t_node *temp = stack->top;
   while(temp)
   {
      escribir_numero(temp->value);
      write(1, " ", 1),
      temp = temp->next;
   }
   write(1, "\n", 1);
   temp = stack->top;
   while(temp)
   {
      t_node *sig = temp->next;
      free(temp);
      temp = sig;
   }
}