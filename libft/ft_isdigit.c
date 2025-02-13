/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 17:38:15 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 13:43:56 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h> 
int main(void)
{
    char test_chars[] = {'0', '5', '9', 'a', '!', ' ', 'Z'};
    size_t i;  // Usar size_t para el tamaño del array

    // Comparación de ft_isdigit con la función estándar isdigit
    for (i = 0; i < sizeof(test_chars); i++) {
        char c = test_chars[i];

        printf("Probando el carácter '%c' (%d):\n", c, c);
        printf("ft_isdigit: %d\n", ft_isdigit(c));
        printf("isdigit estándar: %d\n\n", isdigit(c));
    }

    return 0;
}*/
