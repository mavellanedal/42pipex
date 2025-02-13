/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:46:33 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 13:48:14 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h> 
int main(void)
{
    int test_values[] = {31, 32, 65, 126, 127, 255};
    size_t i;  // Usar size_t para el tamaño del array

    // Comparación de ft_isprint con la función estándar isprint
    for (i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++) {
        int value = test_values[i];

        printf("Probando el valor %d:\n", value);
        printf("ft_isprint: %d\n", ft_isprint(value));
        printf("isprint estándar: %d\n\n", isprint(value));
    }

    return 0;
}*/
