/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:53:47 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/04 19:46:53 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(char *message)
{
	ft_putendl_fd(message, 1);
	exit(1);
}

int	valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_lstsize(t_stack *lst)
{
	int		count;
	t_node	*current;

	count = 0;
	if (!lst)
		return (0);
	current = lst->top;
	while (current)
	{
		count++;
		current = current->next;
	}
	return (count);
}

int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}
