/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelmo <miguelmo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:53:47 by miguelmo          #+#    #+#             */
/*   Updated: 2025/07/25 17:42:11 by miguelmo         ###   ########.fr       */
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
			if (!ft_strchr(s, c))
				s_len = ft_strlen(s);
			else
				s_len = ft_strchr (s, c) - s;
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