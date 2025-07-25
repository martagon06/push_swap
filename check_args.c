/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 19:59:09 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/25 19:01:27 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  check_repetion(char **arguments, int number, int pos)
{
   while(arguments[pos] != NULL)
   {
      if (ft_atoi(arguments[pos]) == number)
         return 1;
      pos++;   
   }
   return 0;
}
void parse_args(t_stack *a, int argc, char **argv)
{
 int i;
 char **temporal;
 int value;

 if (argc == 2)
   temporal = ft_split(argv[1], " ");
 else 
   temporal = argv + 1 ;
   while (i < argc)
 {
   t_node *node = NULL;
   if (!valid_number(temporal[i]))
      error_message("Error");
   value = ft_atoi(argv[i]);
   if (check_repetion(temporal, value, i + 1) == 1)  
      error_message("Error");   
   node = create_node(value);
   if(!node)
      error_message("Error");
   add_node(a, node);
   i++;
 }
 if (argc == 2)
   free_temporal(temporal);
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