/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:03:06 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/19 13:21:18 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
int main(void)
{
    const char str1[] = "abcdef";
    const char str2[] = "abcxyz";
    int result;

    // Comparar los primeros 3 bytes
    result = ft_memcmp(str1, str2, 3);
    if (result == 0)
        printf("Los primeros 3 bytes son iguales.\n");
    else
        printf("Los primeros 3 bytes son diferentes. Resultado: %d\n", result);

    // Comparar los primeros 6 bytes
    result = ft_memcmp(str1, str2, 6);
    if (result == 0)
        printf("Los primeros 6 bytes son iguales.\n");
    else
        printf("Los primeros 6 bytes son diferentes. Resultado: %d\n", result);

    // Comparar cadenas completamente diferentes
    const char str3[] = "12345";
    const char str4[] = "54321";
    result = ft_memcmp(str3, str4, 5);
    if (result == 0)
        printf("Las cadenas '%s' y '%s' son iguales.\n", str3, str4);

    return 0;
}*/
