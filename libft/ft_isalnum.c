/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:30:29 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/18 16:50:00 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char test_chars[] = {'A', 'z', '5', '!', ' ', '\n'};
    size_t i;

    // Comparación de ft_isalnum con la función estándar isalnum
    for (i = 0; i < sizeof(test_chars); i++) {
        char c = test_chars[i];

        printf("Probando el carácter '%c' (%d):\n", c, c);
        printf("ft_isalnum: %d\n", ft_isalnum(c));
        printf("isalnum estándar: %d\n\n", isalnum(c));
    }

    return 0;
}*/
