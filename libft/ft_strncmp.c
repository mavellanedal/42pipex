/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:12:53 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/25 17:35:35 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <stdio.h>
int main(void)
{
    // Pruebas para ft_strncmp
    const char *str1 = "Hello";
    const char *str2 = "Hello, World!";
    size_t n;

    printf("Comparaciones de ft_strncmp:\n");

    for (n = 0; n <= 10; n++)
    {
        int result = ft_strncmp(str1, str2, n);
        printf("Comparando los primeros %zu caracteres: %d\n", n, result); 
    }

    return 0;
}*/
