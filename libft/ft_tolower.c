/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:39:26 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/18 17:50:02 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*#include <stdio.h>
int main(void)
{
    // Pruebas para ft_tolower
    char test_chars[] = {'A', 'B', 'C', 'Z', 'a', '1', ' '};
    size_t i;

    printf("Pruebas de ft_tolower:\n");
    for (i = 0; i < sizeof(test_chars) / sizeof(test_chars[0]); i++)
    {
        char original = test_chars[i];
        char lowercased = ft_tolower(original);
        printf("Original: %c, Lowercase: %c\n", original, lowercased);
    }

    return 0;
}*/
