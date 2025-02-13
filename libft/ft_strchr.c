/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 17:50:44 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 16:36:05 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c_c;
	int				s_len;
	int				i;

	c_c = c;
	s_len = ft_strlen(s);
	i = 0;
	while (i < s_len)
	{
		if (s[i] == c_c)
			return ((char *)s + i);
		i++;
	}
	if (c_c == '\0')
		return ((char *)s + i);
	return (NULL);
}

/*#include <stdio.h>
int main(void)
{
    // Pruebas para ft_strchr
    const char *str = "Hello, World!";
    char search_char = 'o';
    char *result;

    result = ft_strchr(str, search_char);
    if (result != NULL)
    {
        printf("Primera aparición de '%c': %s\n", search_char, result);
    }
    else
    {
        printf("Carácter '%c' no encontrado.\n", search_char);
    }

    return 0;
}*/
