/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:15:31 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/24 16:24:02 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>

int	ft_safe_malloc(char **token_v, int position, size_t buffer)
{
	int	i;

	i = 0;
	token_v[position] = malloc(buffer);
	if (token_v[position] == NULL)
	{
		while (i < position)
		{
			free(token_v[i++]);
		}
		free(token_v);
		return (1);
	}
	return (0);
}

int	ft_fill( char **token_v, char const *s, char delimeter)
{
	size_t		len;
	int			j;
	const char	*start;

	j = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			++s;
		start = s;
		while (*s != delimeter && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (ft_safe_malloc(token_v, j, len + 1))
				return (1);
			ft_strlcpy(token_v[j], start, len + 1);
			j++;
		}
	}
	return (0);
}

size_t	ft_count_tokens(char const *s, char delimeter)
{
	size_t	tokens;
	bool	inside_token;

	tokens = 0;
	while (*s)
	{
		inside_token = false;
		while (*s == delimeter && *s)
			++s;
		while (*s != delimeter && *s)
		{
			if (!inside_token)
			{
				++tokens;
				inside_token = true;
			}
			++s;
		}
	}
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	size_t	tokens;
	char	**token_v;

	if (NULL == s)
		return (NULL);
	tokens = 0;
	tokens = ft_count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (token_v == NULL)
		return (NULL);
	token_v[tokens] = NULL;
	if (ft_fill(token_v, s, c))
		return (NULL);
	return (token_v);
}

/*#include <stdio.h>
int	main(void)
{
	char	*s = "zzzHolazzMundozzzzSoyzzMiquel!";
	char	**v = ft_split(s, 'z');
	while (*v)
		printf("%s\n", *v++);
}*/
