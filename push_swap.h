/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 19:10:08 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/25 19:01:30 by miguelmo         ###   ########.fr       */
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

typedef struct s_stack {
    int size;
    t_node  *top;
    t_node  *bottom;
} t_stack;


//utils
int     ft_isspace(int c);
int	    ft_atoi(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int	    ft_isdigit(char c);
void	error_message(char *message);
int     valid_number(char *str);





#endif