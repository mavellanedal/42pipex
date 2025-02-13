/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:01:34 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 13:47:19 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char test_chars[] = {'A', 'b', '1', '!', ' ', 'z', '\n'};
    size_t i;  // Usar size_t para el tamaño del array

    // Comparación de ft_isalpha con la función estándar isalpha
    for (i = 0; i < sizeof(test_chars); i++) {
        char c = test_chars[i];

        printf("Probando el carácter '%c' (%d):\n", c, c);
        printf("ft_isalpha: %d\n", ft_isalpha(c));
        printf("isalpha estándar: %d\n\n", isalpha(c));
    }

    return 0;
}*/
