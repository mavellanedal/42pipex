/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:34:22 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/19 17:05:57 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dst = malloc(len + 1);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/*#include <stdio.h>
int main(void)
{
    const char *original = "Hola Mundo!";
    char *duplicate = ft_strdup(original);

    if (duplicate)
    {
        printf("Cadena original: %s\n", original);
        printf("Cadena duplicada: %s\n", duplicate);
        free(duplicate); // Liberar la memoria asignada
    }
    else
    {
        printf("Error al duplicar la cadena\n");
    }

    return 0;
}*/
