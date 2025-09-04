/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:08:48 by miguelmo          #+#    #+#             */
/*   Updated: 2025/09/04 19:32:53 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = create_stack();
	b = create_stack();
	if (argc < 2)
	{
		return (1);
	}
	parse_args(&a, argc, argv);
	normalize(a);
	rinyshort(a, b);
	free_stack(a);
	free_stack(b);
	return (0);
}
