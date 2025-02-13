/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:43:31 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 17:24:20 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	size;

	size = ft_strlen(s);
	if (size < len)
		len = size;
	if (start > size)
		start = size;
	if (start + len > size)
		len = size - start;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
    char *substring = ft_substr("tripouille", 1, 1);
    if (substring)
    {
        printf("Subcadena: %s\n", substring);
        free(substring); // Liberar la memoria asignada
    }
    else
    {
        printf("Error al crear la subcadena\n");
    }

    return 0;
}*/
