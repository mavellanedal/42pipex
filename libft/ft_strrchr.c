/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:56:43 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 16:42:26 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	c_c;

	c_c = (char )c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == c_c)
			return ((char *)s + i);
		i--;
	}
	if (c_c == '\0')
		return ((char *)s + i);
	return (NULL);
}

/*#include <stdio.h>
int main(void)
{
    // Pruebas para ft_strrchr
    const char *str = "tripouille";
    char search_char = 'z';
    char *result;

    result = ft_strrchr(str, search_char);
    if (result != NULL)
    {
        printf("Última aparición de '%c': %s\n", search_char, result);
    }
    else
    {
        printf("Carácter '%c' no encontrado.\n", search_char);
    }

    return 0;
}*/
