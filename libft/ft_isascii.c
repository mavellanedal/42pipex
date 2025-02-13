/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:39:17 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 13:47:38 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h> 
int main(void)
{
    int test_values[] = {-1, 0, 65, 127, 128, 255};
    size_t i;  // Usar size_t para el tamaño del array

    // Comparación de ft_isascii con la función estándar isascii
    for (i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++) {
        int value = test_values[i];

        printf("Probando el valor %d:\n", value);
        printf("ft_isascii: %d\n", ft_isascii(value));
        printf("isascii estándar: %d\n\n", isascii(value));
    }

    return 0;
}*/
