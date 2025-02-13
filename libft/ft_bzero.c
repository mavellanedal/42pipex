/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:06:15 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/18 16:34:49 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
#include <stdio.h>
#include <string.h>  // Para comparar con la función original bzero

int main(void)
{
    char test1[20] = "Hello, World!";
    char test2[20] = "Hello, World!";
    size_t n = 5;

   ft_bzero(test1, n);
   bzero(test2, n);

    // Mostrar los resultados
    printf("Resultado de ft_bzero: ");
    for (size_t i = 0; i < sizeof(test1); i++) {
        printf("%d ", test1[i]);
    }
    printf("\n");
    printf("Resultado de bzero estándar: ");
    for (size_t i = 0; i < sizeof(test2); i++) {
        printf("%d ", test2[i]);
    }
    printf("\n");

    return 0;
}*/
