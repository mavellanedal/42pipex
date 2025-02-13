/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:36:22 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/18 17:44:34 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		c -= 32;
	}
	return (c);
}

/*#include <stdio.h>
int main(void)
{
    // Pruebas para ft_toupper
    char test_chars[] = {'a', 'b', 'c', 'z', 'A', '1', ' '};
    size_t i;

    printf("Pruebas de ft_toupper:\n");
    for (i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
    {
        char original = test_chars[i];
        char uppercased = ft_toupper(original);
        printf("Original: %c, Uppercase: %c\n", original, uppercased);
    }

    return 0;
}*/
