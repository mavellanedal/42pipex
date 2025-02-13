/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:50:50 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/19 13:12:09 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*char_s;

	char_s = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)char_s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>
int main(void)
{
    const char arr[] = "Hello, World!";
    char c = 'W';
    char *result;

    // Llamada a ft_memchr para buscar 'W' en arr
    result = ft_memchr(arr, c, sizeof(arr));

    if (result != NULL)
    {
        printf("Se encontró '%c' en la posición: %ld\n", c, result - arr);
    }
    else
    {
        printf("'%c' no encontrado.\n", c);
    }

    // Otra prueba: buscar un carácter que no está en el array
    c = 'z';
    result = ft_memchr(arr, c, sizeof(arr));

    if (result != NULL)
    {
        printf("Se encontró '%c' en la posición: %ld\n", c, result - arr);
    }
    else
    {
        printf("'%c' no encontrado.\n", c);
    }

    return 0;
}*/
