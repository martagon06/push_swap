/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:53:47 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/30 18:59:26 by miguelmo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_countwords(const char *s, char c)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		if (*s != c)
		{
			++ret;
			while (*s && *s != c)
				++s;
		}
		else
			++s;
	}
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	i;
	char			**str;
	size_t			s_len;

	i = 0;
	str = (char **)malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!s || !str)
		return (0);
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			char *next_c = ft_strchr(s, c);
			if (!next_c)
				s_len = ft_strlen(s);
			else
				s_len = next_c - s;
			str[i++] = ft_substr(s, 0, s_len);
			s = s + s_len;
		}
	}
	str[i] = NULL;
	return (str);
}

void	error_message(char *message)
{
	ft_putendl_fd(message, 1);
	exit(1);
}

int valid_number(char *str)
{
	int i = 0;
	if (str[i] == '+' || str[i] == '-') 
		i++;
    if (str[i] == '\0') 
		return 0;
    while (str[i]) {
        if (!ft_isdigit(str[i]))
            return 0;
        i++;
    }
    return 1;
}


int		ft_lstsize(t_stack *lst)
{
	int count;

	count = 0;
	while(lst != NULL)
	{
		count++;
		lst = lst->top->next;
	}
	return count;
}