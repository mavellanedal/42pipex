/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:57:48 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/18 17:05:19 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*p;

	p = (char *)s;
	while (n > 0)
	{
		p[n - 1] = c;
		n--;
	}
	return (s);
}
/*
#include <stdio.h>
#include <string.h>
int main(void)
{
    char buffer1[20];
    char buffer2[20];
    size_t n = 10;  // Número de bytes a establecer
    int value = 'A';  // Valor a establecer en la memoria

    // Usar ft_memset
    ft_memset(buffer1, value, n);

    // Usar la función estándar memset para comparar
    memset(buffer2, value, n);

    // Mostrar los resultados
    printf("Resultado de ft_memset: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%c", buffer1[i]);
    }
    printf("\n");

    printf("Resultado de memset estándar: ");
    for (size_t i = 0; i < n; i++)
    {
        printf("%c", buffer2[i]);
    }
    printf("\n");

    return 0;
}*/
