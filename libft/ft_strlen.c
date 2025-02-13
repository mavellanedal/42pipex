/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <mavellan@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 15:49:44 by mavellan          #+#    #+#             */
/*   Updated: 2025/01/28 09:39:43 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*#include <stdio.h>
int main(void)
{
    // Pruebas para ft_strlen
    const char *test_str1 = "Hello, World!";
    const char *test_str2 = "ft_strlen";
    const char *test_str3 = "";  // Cadena vacía

    size_t len1 = ft_strlen(test_str1);
    size_t len2 = ft_strlen(test_str2);
    size_t len3 = ft_strlen(test_str3);

    // Mostrar los resultados
    printf("Longitud de '%s': %zu\n", test_str1, len1);
    printf("Longitud de '%s': %zu\n", test_str2, len2);
    printf("Longitud de una cadena vacía: %zu\n", len3);

    return 0;
}*/
