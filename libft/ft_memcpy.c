/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:17:55 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/18 17:03:26 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
    char src[] = "Hello, World!";
    char dst1[20];
    char dst2[20];
    size_t n = 5;  // Número de bytes a copiar

    // Usar ft_memcpy
    ft_memcpy(dst1, src, n);
    dst1[n] = '\0';  // Asegúrate de que la cadena se termina correctamente

    // Usar la función estándar memcpy para comparar
    memcpy(dst2, src, n);
    dst2[n] = '\0';  // Asegúrate de que la cadena se termina correctamente

    // Mostrar los resultados
    printf("Resultado de ft_memcpy: %s\n", dst1);
    printf("Resultado de memcpy estándar: %s\n", dst2);

    return 0;
}*/
