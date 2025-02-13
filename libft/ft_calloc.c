/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavellan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:21:50 by mavellan          #+#    #+#             */
/*   Updated: 2024/09/19 17:07:02 by mavellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/*#include <stdio.h>
int main(void)
{
    int *arr;
    size_t n = 5;

    // Llamada a ft_calloc
    arr = (int *)ft_calloc(n, sizeof(int));

    if (arr == NULL)
    {
        printf("Error al asignar memoria\n");
        return 1;
    }

    // Mostrar los valores iniciales del array (todos deben ser 0)
    for (size_t i = 0; i < n; i++)
    {
        printf("arr[%zu] = %d\n", i, arr[i]);
    }

    // Liberar la memoria asignada
    free(arr);

    return 0;
}*/
