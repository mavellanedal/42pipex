/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 17:18:12 by mavellan          #+#    #+#             */
/*   Updated: 2024/10/03 16:41:55 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	if (dst == NULL)
		return (0);
	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (src == NULL)
		return (dst_len);
	if (size <= dst_len)
		return (size + src_len);
	while ((src[i]) && (dst_len + i + 1) < size)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if ((dst_len + i) < size)
		dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*#include <stdio.h>
int main(void)
{
    char dest1[20] = "Hello";
    char src[] = " World!";
    size_t size = sizeof(dest1);  // Tamaño total del buffer destino

    // Usar ft_strlcat
    size_t result1 = ft_strlcat(dest1, src, size);

    // Mostrar el resultado de ft_strlcat
    printf("Resultado de ft_strlcat: %s\n", dest1);
    printf("Tamaño total esperado (ft_strlcat): %zu\n", result1);

    return 0;
}*/
