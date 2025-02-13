/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 17:30:15 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 16:42:48 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_set(s1[start], set))
		start++;
	while (end > start && ft_set(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}

/*#include <stdio.h>
int main(void)
{
    char const *original = "  **Hola Mundo**  ";
    char const *set = " *";  // Caracteres a eliminar del inicio y fin
    char *trimmed;

    // Llamada a ft_strtrim
    trimmed = ft_strtrim(original, set);

    if (trimmed)
    {
        printf("Cadena original: \"%s\"\n", original);
        printf("Cadena recortada: \"%s\"\n", trimmed);
        free(trimmed); // Liberar la memoria asignada
    }
    else
    {
        printf("Error al crear la cadena recortada\n");
    }

    return 0;
}*/
